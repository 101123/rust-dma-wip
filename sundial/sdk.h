#pragma once

#include "offsets.h"
#include "offsets_manual.h"
#include "scatter.h"    

#include <unity/Vector2.h>
#include <unity/Vector3.h>
#include <unity/Vector4.h>

using vec2 = Vector2f;
using vec3 = Vector3f;
using vec4 = Vector4f;

class Il2CppClass;
class terrain_height_map;
class terrain_splat_map;
class terrain_topology_map;
class terrain_texturing;
class terrain_meta;

template <typename T>
struct NativeArray {
    void* m_Buffer;
    int m_Length;
    int m_AllocatorLabel;

    std::pair<int, T*> get() {
        if ( !m_Buffer || !m_Length )
            return { 0, nullptr };

        T* buffer = new T[ m_Length ];
        read_memory( m_Buffer, buffer, m_Length * sizeof( T ) );

        return { m_Length, buffer };
    }
};

class Il2CppClass {
public:
    FIELD( uintptr_t, static_fields, Offsets::Il2CppClass::static_fields );
};

template <typename T, void( *DecryptHandle )( uint32_t* )>
class HiddenValue {
public:
    [[msvc::no_unique_address]] Field<uintptr_t, Offsets::HiddenValue::_handle, DecryptHandle> _handle;
};

#define HIDDEN_VALUE( Type, Name, Offset, DecryptHandle ) \
    static void _Decrypt##Name( uint32_t* values ) { for ( size_t i = 0; i < ( sizeof( uintptr_t ) / sizeof( uint32_t ) ); i++ ) { DecryptHandle } }; \
    [[msvc::no_unique_address]] Field<HiddenValue<Type, _Decrypt##Name>*, Offset> Name

class base_player;

template <typename T>
class Array {
private:
    uint8_t _[ 0x18 ];
public:
    uint64_t _size;
    T _buffer[ 0 ];

    T* read_all( int count, void* buffer = nullptr ) {
        T* items = buffer ? ( T* )buffer : new T[ count ];
        read_memory( _buffer, items, count * sizeof( T ) );
        return items;
    }
};

template <typename T>
class List {
private:
    uint8_t _[ 0x10 ];
public:
    Array<T>* _items;
    int _size;
};

template <typename Key, typename Value>
class Dictionary {
public:
    struct Entry {
        int hashCode;
        int next;
        Key key;
        Value value;
    };

    FIELD( Array<Entry>*, _entries, 0x18 );
    FIELD( int, _count, 0x20 );
};

template <typename T>
class BufferList {
public:
    FIELD( int, count, Offsets::System_BufferList::count );
    FIELD( Array<T>*, buffer, Offsets::System_BufferList::buffer );

    std::tuple<int, Array<T>*> get() {
        uint8_t _[ 128 ];
        return read_memory<int, Array<T>*>( this, { Offsets::System_BufferList::count, Offsets::System_BufferList::buffer }, _ );
    }
};

template <typename Key, typename Value>
class ListDictionary {
public:
    FIELD( BufferList<Value>*, vals, Offsets::System_ListDictionary::vals );
};


namespace Unity {
    namespace Offsets {
        constexpr const static size_t g_PlayerIsFocused = 0x1C00980;
        constexpr const static size_t g_TimeManager = 0x1CA3978;

        namespace GameObject {
            constexpr const static size_t m_ScriptingObject = 0x28;
            constexpr const static size_t m_Component = 0x30;
            constexpr const static size_t m_IsActive = 0x56;
            constexpr const static size_t m_Name = 0x60;
        }

        namespace Component {
            constexpr const static size_t m_ScriptingObject = 0x28;
            constexpr const static size_t m_GameObject = 0x30;
        }

        namespace TransformHierarchy {
            constexpr const static size_t m_LocalTransforms = 0x18;
            constexpr const static size_t m_ParentIndices = 0x20;
            constexpr const static size_t m_LocalPosition = 0x90;
        }

        namespace Transform {
            constexpr const static size_t m_TransformAccess = 0x38;
            constexpr const static size_t m_Children = 0x70;
        }

        namespace Camera {
            constexpr const static size_t m_WorldToClipMatrix = 0x30C;
            constexpr const static size_t m_CullingMask = 0x43C;
            constexpr const static size_t m_LastPosition = 0x454;
        }

        namespace TimeManager {
            constexpr const static size_t m_RealTime = 0x70;
            constexpr const static size_t m_ActiveTime = 0x90;
            constexpr const static size_t m_FrameCount = 0xC8;
        }
    }

    class Transform {

    };
}

template <typename T = uintptr_t>
class Object {
public:
    FIELD( T, cached_ptr, Offsets::Object::m_CachedPtr );
};

class Transform : public Object<Unity::Transform*> {

};






class base_networkable {
public:
    class entity_realm {
    public:
        typedef ListDictionary<uint64_t, base_networkable*>* Type;
        HIDDEN_VALUE( Type, entity_list, Offsets::BaseNetworkable_EntityRealm::entityList,
            {
                values[ i ] = ( ( ( values[ i ] << 22 ) |
                    ( values[ i ] >> 10 ) ) - 1225147140 ) ^ 0xFA11D865;
            }
        );
    };

    class static_fields {
    public:
        HIDDEN_VALUE( entity_realm*, client_entities, Offsets::BaseNetworkable_Static::clientEntities,
            {
                values[ i ] = ( ( ( values[ i ] - 2068828434 ) << 13 ) |
                    ( ( unsigned int )( values[ i ] - 2068828434 ) >> 19 ) ) - 789718271;
            }
        );
    };

    static inline static_fields* static_fields;
};




class model {
public:
    FIELD( Array<Transform*>*, bone_transforms, Offsets::Model::boneTransforms );
};


class base_entity {
public:
    FIELD( model*, model, Offsets::BaseEntity::model );
    FIELD( int, flags, Offsets::BaseEntity::flags );
};






class base_combat_entity : public base_entity {
public:
    FIELD( int, lifestate, Offsets::BaseCombatEntity::lifestate );
    FIELD( float, health, Offsets::BaseCombatEntity::_health );
    FIELD( float, max_health, Offsets::BaseCombatEntity::_maxHealth );
};





class player_model {
public:

};

class player_input {
public:

};

class base_movement {
public:

};

class player_walk_movement : public base_movement {
public:

};

class base_player : public base_combat_entity {
public:
    class static_fields {
    public:
        typedef ListDictionary<uint64_t, base_player*>* Type;
        HIDDEN_VALUE( Type, visible_player_list, Offsets::BasePlayer_Static::visiblePlayerList,
            {
                values[ i ] = ( ( ( values[ i ] - 2068828434 ) << 13 ) |
                    ( ( unsigned int )( values[ i ] - 2068828434 ) >> 19 ) ) - 789718271;
            }
        );
    };

    FIELD( player_model*, player_model, Offsets::BasePlayer::playerModel );
    FIELD( player_input*, input, Offsets::BasePlayer::input );
    FIELD( player_walk_movement*, movement, Offsets::BasePlayer::movement );
    FIELD( uint64_t, current_team, Offsets::BasePlayer::currentTeam );

    inline static static_fields* static_fields;
};






class camera {
public:

};


class main_camera {
public:
    class static_fields {
    public:
        FIELD( camera*, main_camera, Offsets::MainCamera::mainCamera );
    };

    inline static static_fields* static_fields;
};




class world {
public:
    class static_fields {
    public:
        FIELD( int, size, Offsets::World_Static::_size );
    };

    inline static static_fields* static_fields;
};

#define BYTE_TO_FLOAT( b ) ( float )b * 0.003921569f
#define FLOAT_TO_BYTE( f ) ( uint8_t )f * 255.999f;
#define SHORT_TO_FLOAT( s ) ( float )s * 3.051944E-05f;

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

class mathf {
public:
    static bool is_power_of_two( int value ) {
        return ( value & ( value - 1 ) ) == 0;
    }

    static int clamp( int value, int min, int max ) {
        return ( value < min ) ? min : ( value > max ) ? max : value;
    }

    static float clamp( float value, float min, float max ) {
        return ( value < min ) ? min : ( value > max ) ? max : value;
    }

    static float clamp01( float value ) {
        return ( value < 0.f ) ? 0.f : ( value > 1.f ) ? 1.f : value;
    }

    static int min( int a, int b ) {
        return a < b ? a : b;
    }

    static float max( float a, float b ) {
        return a > b ? a : b;
    }

    static float lerp( float a, float b, float t ) {
        return a + ( b - a ) * clamp01( t );
    }
};

template <typename T>
class terrain_map {
public:
    FIELD( int, res, Offsets::TerrainMap::res );
    FIELD( NativeArray<T>, src, Offsets::TerrainMap::src );

    int index( float normalized, int res ) {
        int num = ( int )( normalized * ( float )res );
        if ( num < 0 ) {
            return 0;
        }

        else if ( num <= res - 1 ) {
            return num;
        }

        return res - 1;
    }
};

class terrain_height_map : public terrain_map<uint16_t> {
public:
    FIELD( float, norm_y, Offsets::TerrainHeightMap::normY );

    float get_height( float norm_x, float norm_z, vec3 terrain_position, vec3 terrain_size, int res, uint16_t* height_map );
    float get_height_01( float norm_x, float norm_z, int res, uint16_t* height_map );
    float get_height_01( int x, int z, int res, uint16_t* height_map );
    vec3 get_normal( float norm_x, float norm_z, int res, uint16_t* height_map, float norm_y );
    vec3 get_normal( int x, int z, int res, uint16_t* height_map, float norm_y );
};

class terrain_splat_map : public terrain_map<uint8_t> {
public:
    float get_splat( float norm_x, float norm_z, int mask, int res, uint8_t* splat_map );
    float get_splat( int x, int z, int mask, int res, uint8_t* splat_map );
};

class terrain_topology_map : public terrain_map<int32_t> {
public:
    int get_topology( float norm_x, float norm_z, float radius, vec3 terrain_one_over_size, int res, int32_t* topology_map );
};

class terrain_texturing {
public:
    FIELD( float, terrain_size, Offsets::TerrainTexturing::terrainSize );
    FIELD( int, shore_map_size, Offsets::TerrainTexturing::shoreMapSize );
    FIELD( float, shore_distance_scale, Offsets::TerrainTexturing::shoreDistanceScale );
    FIELD( NativeArray<vec4>, shore_vectors, Offsets::TerrainTexturing::shoreVectors );

    std::pair<vec3, float> get_coarse_vector_to_shore( vec2 uv, int shore_map_size, vec4* shore_vectors, float shore_distance_scale );
};

class terrain_meta {
public:
    class static_fields {
    public:
        FIELD( vec3, position, Offsets::TerrainMeta::Position );
        FIELD( vec3, size, Offsets::TerrainMeta::Size );
        FIELD( vec3, one_over_size, Offsets::TerrainMeta::OneOverSize );
        FIELD( terrain_height_map*, height_map, Offsets::TerrainMeta::HeightMap );
        FIELD( terrain_splat_map*, splat_map, Offsets::TerrainMeta::SplatMap );
        FIELD( terrain_topology_map*, topology_map, Offsets::TerrainMeta::TopologyMap );
        FIELD( terrain_texturing*, texturing, Offsets::TerrainMeta::Texturing );
    };

    static inline static_fields* static_fields;
};
