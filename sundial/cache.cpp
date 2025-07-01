#include "cache.h"

#include "sdk.h"
#include "global.h"
#include "il2cpp.h"

BufferList<base_networkable*>* cached_entity_list;
BufferList<base_player*>* cached_player_list;

bool populate_entity_lists() {
	if ( !cached_entity_list ) {
		auto client_entities_hidden_value = base_networkable::static_fields->client_entities.value;
		if ( client_entities_hidden_value ) {
			base_networkable::entity_realm* client_entities = nullptr;
			if ( il2cpp_gchandle_get_target( client_entities_hidden_value->_handle, &client_entities ) ) {
				auto entity_list_hidden_value = client_entities->entity_list.value;
				if ( entity_list_hidden_value ) {
					ListDictionary<uint64_t, base_networkable*>* entity_list = nullptr;
					if ( il2cpp_gchandle_get_target( entity_list_hidden_value->_handle, &entity_list ) ) {
						BufferList<base_networkable*>* vals = entity_list->vals;
						// Validate that list is currently valid before we cache
						if ( vals ) {
							Array<base_networkable*>* buffer = vals->buffer;
							int count = vals->count;
							if ( buffer && count > 0 && count < 65536 ) {
								cached_entity_list = vals;
							}
						}
					}
				}
			}
		}
	}

	if ( !cached_player_list ) {
		auto visible_player_list_hidden_value = base_player::static_fields->visible_player_list.value;
		if ( visible_player_list_hidden_value ) {
			ListDictionary<uint64_t, base_player*>* visible_player_list = nullptr;
			if ( il2cpp_gchandle_get_target( visible_player_list_hidden_value->_handle, &visible_player_list ) ) {
				BufferList<base_player*>* vals = visible_player_list->vals;
				// Validate that list is currently valid before we cache
				if ( vals ) {
					Array<base_player*>* buffer = vals->buffer;
					int count = vals->count;
					if ( buffer && count > 0 && count < 65536 ) {
						cached_player_list = vals;
					}
				}
			}
		}
	}

	LOG( "%p %p\n", cached_entity_list, cached_player_list );

	return cached_entity_list && cached_player_list;
}

#include <spsc-queue.hpp>

enum bones {
	neck = 46,
	head = 47,
	spine1 = 18,
	spine3 = 21,
	spine4 = 22,
	l_clavicle = 23,
	r_clavicle = 54,
	l_upperarm = 24,
	r_upperarm = 55,
	l_forearm = 25,
	r_forearm = 56,
	l_hand = 26,
	r_hand = 57,
	l_hip = 1,
	r_hip = 13,
	l_knee = 2,
	r_knee = 14,
	l_foot = 3,
	r_foot = 15
};

static int skeleton_bones[] = {
	neck,
	head,
	spine1, spine4,
	l_clavicle, r_clavicle,
	l_upperarm, r_upperarm,
	l_forearm, r_forearm,
	l_hand, r_hand,
	l_hip, r_hip,
	l_knee, r_knee,
	l_foot, r_foot
};

struct player_transient_data {
	bool m_valid;
	model* m_model;
	Array<Transform*>* m_bone_transforms_ptr;
	Array<Transform*> m_bone_transforms_arr;
	Transform* m_bone_transforms[ 128 ];
	Unity::Transform* m_internal_bone_transforms[ _countof( skeleton_bones ) ];

	//Transform** m_bone_transforms;
};

void cache_players( scatter_request* scatter ) {
	auto [ count, buffer ] = cached_player_list->get();
	if ( !buffer || ( count < 0 || count > 65536 ) )
		return;

	base_player** players = buffer->read_all( count );
	if ( !players )
		return;

	player_transient_data* player_data = new player_transient_data[ count ];
	if ( !player_data )
		return;

	for ( int i = 0; i < count; i++ ) {
		scatter->add_field( &players[ i ]->model, &player_data[ i ].m_model );
	}

	scatter->execute();
	scatter->clear();

	for ( int i = 0; i < count; i++ ) {
		scatter->add_field( &player_data[ i ].m_model->bone_transforms, &player_data[ i ].m_bone_transforms_ptr );
	}

	scatter->execute();
	scatter->clear();

	for ( int i = 0; i < count; i++ ) {
		scatter->add_read( player_data[ i ].m_bone_transforms_ptr, &player_data[ i ].m_bone_transforms_arr );
	}

	scatter->execute();
	scatter->clear();

	for ( int i = 0; i < count; i++ ) {
		uint64_t transform_count = player_data[ i ].m_bone_transforms_arr._size;
		if ( transform_count < 0 || transform_count > 128 ) {
			player_data[ i ].m_valid = false;
			continue;
		}

		scatter->add_read( player_data[ i ].m_bone_transforms_ptr->_buffer, player_data[ i ].m_bone_transforms, transform_count * sizeof( Transform* ) );
	}

	scatter->execute();
	scatter->clear();

	for ( int i = 0; i < count; i++ ) {
		for ( int j = 0; j < _countof( skeleton_bones ); j++ ) {
			Transform* transform = player_data[ i ].m_bone_transforms[ j ];
			if ( !transform )
				continue;

			scatter->add_field( &transform->cached_ptr, &player_data[ i ].m_internal_bone_transforms[ j ] );
		}
	}

	scatter->execute();
	scatter->clear();

	for ( int i = 0; i < count; i++ ) {
		for ( int j = 0; j < _countof( skeleton_bones ); j++ ) {
			LOG( "%d: %p\n", j, player_data[ i ].m_internal_bone_transforms[ j ] );
		}
	}

	delete[] players;
	delete[] player_data;
}

void cache_thread() {
	cache_thread_running = true;

	populate_entity_lists();

	scatter_request scatter;

	cache_players( &scatter );

	cache_thread_running = false;
}