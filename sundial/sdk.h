#pragma once

#include "offsets.h"
#include "offsets_manual.h"
#include "scatter.h"    

#include <math/vec2.h>
#include <math/vec3.h>
#include <math/vec4.h>
#include <math/mat3x3.h>
#include <math/mat4x4.h>

#include <windows.h>
#include <hexrays.h>

class terrain_height_map;
class terrain_splat_map;
class terrain_topology_map;
class terrain_texturing;
class terrain_meta;

class il2cpp_class {
public:
    FIELD( uintptr_t, static_fields, Offsets::Il2CppClass::static_fields );
};

class il2cpp_object {
public:
    FIELD( il2cpp_class*, klass, Offsets::Il2CppObject::klass );
};

template <typename T, void( *DecryptHandle )( uint32_t* )>
class hidden_value {
public:
    [[msvc::no_unique_address]] Field<uint32_t, Offsets::HiddenValue::_handle, DecryptHandle> _handle;
};

#define HIDDEN_VALUE( Type, Name, Offset, DecryptHandle ) \
    static void decrypt_##Name##_handle( uint32_t* values ) { for ( size_t i = 0; i < ( sizeof( uint32_t ) / sizeof( uint32_t ) ); i++ ) { DecryptHandle } }; \
    [[msvc::no_unique_address]] Field<hidden_value<Type, decrypt_##Name##_handle>*, Offset> Name

class base_player;

namespace sys {
    class string {
    private:
        uint8_t _[ 0x10 ];
    public:
        int strlen;
        wchar_t str[ 128 + 1 ];
    };

    template <typename T>
    class array {
    private:
        uint8_t _[ 0x18 ];
    public:
        uint64_t size;
        T buffer[ 0 ];

        T* read_all( int count, void* buffer = nullptr ) {
            T* items = buffer ? ( T* )buffer : new T[ count ];
            read_memory( this->buffer, items, count * sizeof( T ) );
            return items;
        }

        bool read_all( int count, void* buffer, scatter_request* scatter ) {
            return scatter->add_read( this->buffer, buffer, count * sizeof( T ) );
        }
    };

    template <typename T>
    class list {
    private:
        uint8_t _[ 0x10 ];
    public:
        sys::array<T>* items;
        int size;
    };

    template <typename T>
    class buffer_list {
    public:
        FIELD( int, count, Offsets::System_BufferList::count );
        FIELD( sys::array<T>*, buffer, Offsets::System_BufferList::buffer );

        std::tuple<int, sys::array<T>*> get() {
            uint8_t _[ 128 ];
            return read_memory<int, sys::array<T>*>( this, { Offsets::System_BufferList::count, Offsets::System_BufferList::buffer }, _ );
        }
    };

    template <typename K, typename V>
    class dictionary {
    public:
        struct entry {
            int hash_code;
            int next;
            K key;
            V value;
        };

        FIELD( sys::array<entry>*, entries, 0x18 );
        FIELD( int, count, 0x20 );
    };

    template <typename K, typename V>
    class list_dictionary {
    public:
        FIELD( buffer_list<V>*, vals, Offsets::System_ListDictionary::vals );
    };
}

namespace unity {
    namespace collections {
        template <typename T>
        struct native_array {
            void* buffer;
            int length;
            int allocator_label;

            std::pair<int, T*> get() {
                if ( !this->buffer || !this->length )
                    return { 0, nullptr };

                T* buffer = new T[ this->length ];
                read_memory( this->buffer, buffer, length * sizeof( T ) );

                return { length, buffer };
            }
        };
    }

    namespace math {
        class trsx {
        public:
            vec3 t;
        private:
            uint8_t _[ 4 ];
        public:
            vec4 q;
            vec3 s;
        private:
            uint8_t __[ 4 ];
        };
    }

    class transform_internal {
    public:
        transform_internal() = delete;
        transform_internal( fast_vector<math::trsx>* local_transforms, fast_vector<int>* parent_indices ) :
            m_local_transforms( local_transforms ), m_parent_indices( parent_indices ) {};

        vec3 get_position( int index ) {
            math::trsx* local_transforms = m_local_transforms->begin();
            int* parent_indices = m_parent_indices->begin();

            vec3 global_t = local_transforms[ index ].t;
            int parent_index = parent_indices[ index ];

            int iterations = 0;
            while ( parent_index >= 0 && parent_index <= m_local_transforms->capacity() && iterations++ < 256 ) {
                math::trsx& parent = local_transforms[ parent_index ];

                global_t = parent.q * global_t;
                global_t = global_t * parent.s;
                global_t = global_t + parent.t;

                parent_index = parent_indices[ parent_index ];
            }

            return global_t;
        }

    private:
        fast_vector<math::trsx>* m_local_transforms;
        fast_vector<int>* m_parent_indices;
    };


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
            constexpr const static size_t localTransforms = 0x18;
            constexpr const static size_t parentIndices = 0x20;
            constexpr const static size_t m_LocalPosition = 0x90;
        }

        namespace Transform {
            constexpr const static size_t m_TransformData = 0x38;
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

    class camera {
    public:
        FIELD( mat4x4, view_matrix, Offsets::Camera::m_WorldToClipMatrix );
        FIELD( int, layer_mask, Offsets::Camera::m_CullingMask );
        FIELD( vec3, position, Offsets::Camera::m_LastPosition );
    };

    class component {

    };

    class transform_hierarchy {
    public:
        FIELD( math::trsx*, local_transforms, Offsets::TransformHierarchy::localTransforms );
        FIELD( int*, parent_indices, Offsets::TransformHierarchy::parentIndices );
    };

    struct transform_access {
        transform_hierarchy* hierarchy;
        int index;
    };

    class transform : public component {
    public:
        FIELD( transform_access, transform_data, Offsets::Transform::m_TransformData );
    };
}



template <typename T = uintptr_t>
class object : public il2cpp_object {
public:
    FIELD( T, cached_ptr, Offsets::Object::m_CachedPtr );
};

class transform : public object<unity::transform*> {

};

class component : public object<uintptr_t> {

};

class base_networkable : public component {
public:
    class entity_realm {
    public:
        typedef sys::list_dictionary<uint64_t, base_networkable*>* Type;
        HIDDEN_VALUE( Type, entity_list, Offsets::BaseNetworkable_EntityRealm::entityList,
            {
                uint32_t a = ( ( ( values[ i ] + 1174773599 ) << 31 ) |
                    ( ( unsigned int )( values[ i ] + 1174773599 ) >> 1 ) ) ^ 0x20A4ECF6;

                values[ i ] = ( a << 21 ) | ( a >> 11 );
            }
        );
    };

    class static_fields {
    public:
        HIDDEN_VALUE( entity_realm*, client_entities, Offsets::BaseNetworkable_Static::clientEntities,
            {
                int64_t a = 4LL * ( ( ( values[ i ] >> 10 ) |
                    ( values[ i ] << 22 ) ) - 945607450 );

                values[ i ] = a | HIDWORD( a );
            }
        );
    };

    static inline static_fields* s_static_fields;
};




class model {
public:
    FIELD( sys::array<transform*>*, bone_transforms, Offsets::Model::boneTransforms );
};



class base_entity : public base_networkable {
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
    FIELD( vec3, position, Offsets::PlayerModel::position );
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

class model_state {
public:

};

class player_eyes {
public:

};

class item_definition {
public:
    FIELD( int, item_id, Offsets::ItemDefinition::itemid );
};

class item {
public:
    FIELD( float, condition, Offsets::Item::_condition );
    FIELD( float, max_condition, Offsets::Item::_maxCondition );
    FIELD( item_definition*, info, Offsets::Item::info );
    FIELD( uint64_t, uid, Offsets::Item::uid );
    FIELD( int, amount, Offsets::Item::amount );
    FIELD( int, position, Offsets::Item::position );
    //FIELD( item_container*, contents, Offsets::Item::contents );
    FIELD( base_entity*, world_entity, Offsets::Item::worldEnt );
    FIELD( base_entity*, held_entity, Offsets::Item::heldEntity );
};

class item_container {
public:
    FIELD( uint64_t, uid, Offsets::ItemContainer::uid );
    FIELD( sys::list<item*>*, item_list, Offsets::ItemContainer::itemList );
};

class player_loot {
    FIELD( sys::list<item_container*>*, containers, Offsets::PlayerLoot::containers );
};

class player_inventory {
public:
    FIELD( item_container*, container_main, Offsets::PlayerInventory::containerMain );
    FIELD( item_container*, container_belt, Offsets::PlayerInventory::containerBelt );
    FIELD( item_container*, container_wear, Offsets::PlayerInventory::containerWear );
    FIELD( player_loot*, loot, Offsets::PlayerInventory::loot );
};

class base_player : public base_combat_entity {
public:
    class static_fields {
    public:
        typedef sys::list_dictionary<uint64_t, base_player*>* Type;
        HIDDEN_VALUE( Type, visible_player_list, Offsets::BasePlayer_Static::visiblePlayerList,
            {
                int64_t a = 4LL * ( ( ( values[ i ] >> 10 ) |
                    ( values[ i ] << 22 ) ) - 945607450 );

                values[ i ] = a | HIDWORD( a );
            }
        );
    };

    FIELD( player_model*, player_model, Offsets::BasePlayer::playerModel );
    FIELD( player_input*, input, Offsets::BasePlayer::input );
    FIELD( player_walk_movement*, movement, Offsets::BasePlayer::movement );
    FIELD( uint64_t, current_team, Offsets::BasePlayer::currentTeam );

    ENCRYPTED_VALUE( uint64_t, cl_active_item, Offsets::BasePlayer::clActiveItem,
        {
            values[ i ] = ( ( ( values[ i ] + 2037793220 ) << 18 ) |
                ( ( unsigned int )( values[ i ] + 2037793220 ) >> 14 ) ) ^ 0xF7AE84B8;
        }, {}
    );

    FIELD( model_state*, model_state, Offsets::BasePlayer::modelState );
    FIELD( int, player_flags, Offsets::BasePlayer::playerFlags );

    HIDDEN_VALUE( player_eyes*, eyes, Offsets::BasePlayer::eyes,
        {
            values[ i ] = ( ( ( ( values[ i ] << 20 ) | ( values[ i ] >> 12 ) ) ^ 0x7C383ED2 ) << 31 ) |
                ( ( ( ( values[ i ] << 20 ) | ( values[ i ] >> 12 ) ) ^ 0x7C383ED2 ) >> 1 );
        }
    );

    ENCRYPTED_VALUE( uint64_t, user_id, Offsets::BasePlayer::userID,
        {
            values[ i ] = ( ( ( ( values[ i ] << 14 ) | ( values[ i ] >> 18 ) ) - 387645640 ) << 27 ) |
                ( ( ( ( values[ i ] << 14 ) | ( values[ i ] >> 18 ) ) - 387645640 ) >> 5 );
        }, {}
    );

    HIDDEN_VALUE( player_inventory*, inventory, Offsets::BasePlayer::inventory,
        {
            values[ i ] = ( ( ( values[ i ] + 2141602309 ) ^ 0x49D01BA8 ) << 19 ) |
                ( ( ( values[ i ] + 2141602309 ) ^ 0x49D01BA8u ) >> 13 );
        }
    );

    FIELD( sys::string*, display_name, Offsets::BasePlayer::_displayName );

    static inline il2cpp_class* s_klass;
    static inline static_fields* s_static_fields;
};

class scientist_npc : public base_player {
public:
    static inline il2cpp_class* s_klass;
};

class tunnel_dweller : public base_player {
public:
    static inline il2cpp_class* s_klass;
};

class underwater_dweller : public base_player {
public:
    static inline il2cpp_class* s_klass;
};

class scarecrow_npc : public base_player {
public:
    static inline il2cpp_class* s_klass;
};

class gingerbread_npc : public base_player {
public:
    static inline il2cpp_class* s_klass;
};


class camera : public object<unity::camera*> {
public:

};


class main_camera {
public:
    class static_fields {
    public:
        FIELD( camera*, main_camera, Offsets::MainCamera::mainCamera );
    };

    static inline static_fields* s_static_fields;
};




class world {
public:
    class static_fields {
    public:
        FIELD( int, size, Offsets::World_Static::_size );
    };

    static inline static_fields* s_static_fields;
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
    FIELD( unity::collections::native_array<T>, src, Offsets::TerrainMap::src );

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
    FIELD( unity::collections::native_array<vec4>, shore_vectors, Offsets::TerrainTexturing::shoreVectors );

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

    static inline static_fields* s_static_fields;
};
