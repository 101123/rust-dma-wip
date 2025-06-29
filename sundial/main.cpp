#include "renderer.h"
#include "render.h"
#include "assets.h"
#include "dma.h"
#include "global.h"

#include "sdk.h"
#include "memory.h"

#include <memprocfs/leechcore.h>

#include "offsets.h"

bool populated_classes = false;
int populate_classes_tries = 0;

struct class_lookup {
    Il2CppClass** m_value;
    void* m_static_fields;
    uint64_t m_type_definition_index;
};

struct parent_lookup {
    Il2CppClass** m_start;
    Il2CppClass** m_value;
    void* m_static_fields;
    int m_depth;
};

class_lookup class_lookups[] = {
    { nullptr, &TerrainMeta::static_fields, TerrainMeta_TypeDefinitionIndex },
    { nullptr, &World::static_fields, World_Static_TypeDefinitionIndex },
    { nullptr, &MainCamera::static_fields, MainCamera_TypeDefinitionIndex }
};

parent_lookup parent_lookups[] = {

};

bool populate_classes() {
    static uintptr_t type_info_definition_table_address = relative_32(
        find_pattern_image_remote( game_assembly, "\x48\xF7\xE1\x48\x8B\xCA\x48\xC1\xE9\x04\xBA\x08\x00\x00\x00" ) + 21, 3 );

    if ( !type_info_definition_table_address )
        return false;

    Il2CppClass** type_info_definition_table = read_memory<Il2CppClass**>( type_info_definition_table_address );
    if ( !type_info_definition_table )
        return false;

    for ( class_lookup& class_lookup : class_lookups ) {
        Il2CppClass* klass = read_memory<Il2CppClass*>( &type_info_definition_table[ class_lookup.m_type_definition_index ] );
        if ( !klass )
            return false;

        if ( class_lookup.m_value ) {
            *class_lookup.m_value = klass;
        }

        if ( class_lookup.m_static_fields ) {
            *( uintptr_t* )( class_lookup.m_static_fields ) = read_memory<uintptr_t>( klass + 0xB8 );
        }
    }

    return true;
}

template <typename Type, size_t Offset>
class Field {
public:
    operator int() {
        return Offset;
    }

    void* print_this() {
        return this;
    }
};

class PlayerModel {
public:

};

class PlayerInput {
public:

};

class BaseMovement {
public:

};

class BasePlayer {
public:
    Field<PlayerModel*, Offsets::BasePlayer::playerModel> playerModel;
    Field<PlayerInput*, Offsets::BasePlayer::input> input;
    Field<BaseMovement*, Offsets::BasePlayer::movement> movement;
    Field<uint64_t, Offsets::BasePlayer::currentTeam> currentTeam;
    Field<uint64_t, Offsets::BasePlayer::clActiveItem> clActiveItem;

    void* print_this() {
        return this;
    }
};

struct MapImageConfig {
    Vector4 StartColor;
    Vector4 WaterColor;
    Vector4 GravelColor;
    Vector4 DirtColor;
    Vector4 SandColor;
    Vector4 GrassColor;
    Vector4 ForestColor;
    Vector4 RockColor;
    Vector4 SnowColor;
    Vector4 PebbleColor;
    Vector4 OffShoreColor;
    Vector3 SunDirection;
    float SunPower;
    float Brightness;
    float Contrast;
    float Scale;
    float MaxDepth;
    int WorldSize;
    int OceanMargin;
    float* ImageSize;
};

MapImageConfig DefaultConfig = {
    .StartColor = { 0.2863f, 0.2706f, 0.2471f, 1.f },
    .WaterColor = { 0.1694f, 0.3176f, 0.362f, 1.f },
    .GravelColor = { 0.25f, 0.2434f, 0.2204f, 1.f },
    .DirtColor = { 0.6f, 0.4796f, 0.33f, 1.f },
    .SandColor = { 0.7f, 0.6597f, 0.5277f, 1.f },
    .GrassColor = { 0.3549f, 0.37f, 0.2035f, 1.f },
    .ForestColor = { 0.2484f, 0.3f, 0.0703f, 1.f },
    .RockColor = { 0.4f, 0.3938f, 0.3752f, 1.f },
    .SnowColor = { 0.8627f, 0.9294f, 0.9412f, 1.f },
    .PebbleColor = { 0.1373f, 0.2784f, 0.2762f, 1.f },
    .OffShoreColor = { 0.0409f, 0.2206f, 0.2745f, 1.f },
    .SunDirection = { 0.25f, 0.75f, 0.62f },
    .SunPower = 0.65f,
    .Brightness = 0.995f,
    .Contrast = 0.755f,
    .Scale = 1.f,
    .MaxDepth = 50.f,
    .WorldSize = 4000,
    .OceanMargin = 500,
    .ImageSize = nullptr
};

ID3D11ShaderResourceView* render( MapImageConfig* config ) {
    // Initialize these variables here in order to utilize gotos to avoid repeated code
    ID3D11ShaderResourceView* srv = nullptr;
    ID3D11Texture2D* texture = nullptr;

    auto static_fields = TerrainMeta::static_fields;
    if ( !static_fields )
        return nullptr;

    TerrainTexturing* terrain_texturing = static_fields->Texturing;
    if ( !terrain_texturing )
        return nullptr;

    TerrainHeightMap* terrain_height_map = static_fields->HeightMap;
    if ( !terrain_height_map )
        return nullptr;

    TerrainSplatMap* terrain_splat_map = static_fields->SplatMap;
    if ( !terrain_splat_map )
        return nullptr;

    TerrainTopologyMap* terrain_topology_map = static_fields->TopologyMap;
    if ( !terrain_topology_map )
        return nullptr;

    Vector3 terrain_position = static_fields->Position;
    Vector3 terrain_size = static_fields->Size;
    Vector3 terrain_one_over_size = static_fields->OneOverSize;

    int shore_map_size = terrain_texturing->shoreMapSize;
    float shore_distance_scale = terrain_texturing->shoreDistanceScale;
    auto [ shore_vector_count, shore_vectors ] = terrain_texturing->shoreVectors.get();
    if ( !shore_vectors || !shore_vector_count ) 
        return nullptr;

    int height_map_res = terrain_height_map->res;
    float height_map_norm_y = terrain_height_map->normY;
    auto [ height_map_count, height_map ] = terrain_height_map->src.get();
    if ( !height_map || !height_map_count )
        return nullptr;

    int splat_map_res = terrain_splat_map->res;
    auto [ splat_map_count, splat_map ] = terrain_splat_map->src.get();
    if ( !splat_map || !splat_map_count )
        goto cleanup;

    int topology_map_res = terrain_topology_map->res;
    auto [ topology_map_count, topology_map ] = terrain_topology_map->src.get();
    if ( !topology_map || !topology_map_count ) 
        goto cleanup;

    int map_res = ( int )( World::static_fields->_size * Mathf::Clamp( config->Scale, 0.1f, 4.f ) );
    float inv_map_res = 1.f / ( float )map_res;

    if ( map_res <= 0 ) 
        goto cleanup;

    int image_width = map_res + config->OceanMargin * 2;
    int image_height = map_res + config->OceanMargin * 2;
    
    D3D11_TEXTURE2D_DESC texture_desc {
      .Width = ( uint32_t )image_width,
      .Height = ( uint32_t )image_height,
      .MipLevels = 1,
      .ArraySize = 1,
      .Format = DXGI_FORMAT_R8G8B8A8_UNORM,
      .SampleDesc = {
          .Count = 1,
          .Quality = 0
      },

      .Usage = D3D11_USAGE_DYNAMIC,
      .BindFlags = D3D11_BIND_SHADER_RESOURCE,
      .CPUAccessFlags = D3D11_CPU_ACCESS_WRITE,
      .MiscFlags = 0
    };

    if ( renderer.m_device->CreateTexture2D( &texture_desc, nullptr, &texture ) != S_OK ) 
        goto cleanup;

    D3D11_MAPPED_SUBRESOURCE resource;
    if ( renderer.m_device_context->Map( texture, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource ) != S_OK )
        goto cleanup;

    for ( int y = 0; y < image_height; y++ ) {
        int cy = y - config->OceanMargin;
        float y2 = ( float )cy * inv_map_res;
        int w = map_res + config->OceanMargin;

        for ( int cx = -config->OceanMargin; cx < w; cx++ ) {
            float x2 = ( float )cx * inv_map_res;
            float height = terrain_height_map->GetHeight( x2, y2, terrain_position, terrain_size, height_map_res, height_map );

            Vector4 color = config->StartColor;

            color = Lerp( color, config->GravelColor, terrain_splat_map->GetSplat( x2, y2, 7, splat_map_res, splat_map ) * config->GravelColor.w );
            color = Lerp( color, config->PebbleColor, terrain_splat_map->GetSplat( x2, y2, 6, splat_map_res, splat_map ) * config->PebbleColor.w );
            color = Lerp( color, config->RockColor, terrain_splat_map->GetSplat( x2, y2, 3, splat_map_res, splat_map ) * config->RockColor.w );
            color = Lerp( color, config->DirtColor, terrain_splat_map->GetSplat( x2, y2, 0, splat_map_res, splat_map ) * config->DirtColor.w );
            color = Lerp( color, config->GrassColor, terrain_splat_map->GetSplat( x2, y2, 4, splat_map_res, splat_map ) * config->GrassColor.w );
            color = Lerp( color, config->ForestColor, terrain_splat_map->GetSplat( x2, y2, 5, splat_map_res, splat_map ) * config->ForestColor.w );
            color = Lerp( color, config->SandColor, terrain_splat_map->GetSplat( x2, y2, 2, splat_map_res, splat_map ) * config->SandColor.w );
            color = Lerp( color, config->SnowColor, terrain_splat_map->GetSplat( x2, y2, 1, splat_map_res, splat_map ) * config->SnowColor.w );

            float depth_factor = 0.f;
            float shore_distance = terrain_texturing->GetCoarseVectorToShore( Vector2( x2, y2 ), shore_map_size, shore_vectors, shore_distance_scale ).second;

            if ( shore_distance > 0.f ) {
                depth_factor = 0.f - height;    

                if ( depth_factor <= 0.f || !( ( terrain_topology_map->GetTopology( x2, y2, 16.f, terrain_one_over_size, topology_map_res, topology_map ) & 0x180 ) != 0 ) ) {
                    depth_factor = Mathf::Max( depth_factor, 0.1f * shore_distance );
                }
            }

            if ( depth_factor > 0.f ) {
                color = Lerp( color, config->WaterColor, Mathf::Clamp( 0.5f + depth_factor / 5.f, 0.f, 1.f ) );
                color = Lerp( color, config->OffShoreColor, Mathf::Clamp( depth_factor / config->MaxDepth, 0.f, 1.f ) );
            }

            else {
                static const Vector4 half = Vector4( 0.5f, 0.5f, 0.5f, 0.5f );

                float diffuse = Mathf::Max( Dot( terrain_height_map->GetNormal( x2, y2, height_map_res, height_map, height_map_norm_y ), config->SunDirection ), 0.f );

                color = color + ( ( color * config->SunPower ) * ( diffuse - 0.5f ) );
                color = ( color - half ) * config->Contrast + half;
            }

            color = color * config->Brightness;

            int px = cx + config->OceanMargin;
            int py = cy + config->OceanMargin;

            uint8_t* data = ( uint8_t* )resource.pData + ( py * resource.RowPitch ) + ( px * 4 );

            data[ 0 ] = NormalizedToByte( color.x );
            data[ 1 ] = NormalizedToByte( color.y );
            data[ 2 ] = NormalizedToByte( color.z );
            data[ 3 ] = NormalizedToByte( 1.f );    
        }
    }

    renderer.m_device_context->Unmap( texture, 0 );

    D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc {
       .Format = DXGI_FORMAT_R8G8B8A8_UNORM,
       .ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D,
       .Texture2D = {
           .MostDetailedMip = 0,
           .MipLevels = texture_desc.MipLevels
       }
    };

    if ( renderer.m_device->CreateShaderResourceView( texture, &srv_desc, &srv ) != S_OK )
        goto cleanup;

cleanup:
    if ( shore_vectors ) {
        delete[] shore_vectors;
    }

    if ( height_map ) {
        delete[] height_map;
    }

    if ( splat_map ) {
        delete[] splat_map;
    }

    if ( topology_map ) {
        delete[] topology_map;
    }

    if ( texture ) {
        texture->Release();
    }

    return srv;
}

int main() {
    if ( !dma.initialize() ) {
        LOG( "failed to initialize dma!\n" );
        return 1;
    }

    if ( !renderer.initialize() ) {
        LOG( "failed to initialize renderer!\n" );
        return 2;
    }

    uint32_t process_id = dma.get_process_id( "RustClient.exe" );
    if ( !process_id ) {
        LOG( "failed to find rust process!\n" );
        return 3;
    }

    dma.set_process_id( process_id );

    game_assembly = dma.get_module_base_address( "GameAssembly.dll" );
    if ( !game_assembly ) 
        return 4;

    unity_player = dma.get_module_base_address( "UnityPlayer.dll" );
    if ( !unity_player )
        return 5;
    
    while ( !populated_classes && populate_classes_tries++ < 120 ) {
        if ( populated_classes = populate_classes() ) {
            break;
        }

        Sleep( 1000 );
    }

    LOG( "%p\n", MainCamera::static_fields->mainCamera );

    //auto minimap = render( &DefaultConfig );



    while ( true ) {
        renderer.begin_frame();
        //renderer.draw_image( 100.f, 100.f, 400.f, 400.f, minimap );
        renderer.end_frame();
    }

    //CreateThread( NULL, 0, ( LPTHREAD_START_ROUTINE )render_thread, NULL, 0, NULL );

    //while ( true ) {
    //    Sleep( 1000 );
    //}

    return 0;
}