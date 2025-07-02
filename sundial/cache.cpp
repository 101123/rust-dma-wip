#include "cache.h"

#include "sdk.h"
#include "global.h"
#include "il2cpp.h"

#include "shared.h"

#include <windows.h>

sys::buffer_list<base_networkable*>* cached_entity_list;
sys::buffer_list<base_player*>* cached_player_list;

bool populate_entity_lists() {
	if ( !cached_entity_list ) {
		auto client_entities_hidden_value = base_networkable::static_fields->client_entities.value;
		if ( client_entities_hidden_value ) {
			base_networkable::entity_realm* client_entities = nullptr;
			if ( il2cpp_gchandle_get_target( client_entities_hidden_value->_handle, &client_entities ) ) {
				auto entity_list_hidden_value = client_entities->entity_list.value;
				if ( entity_list_hidden_value ) {
					sys::list_dictionary<uint64_t, base_networkable*>* entity_list = nullptr;
					if ( il2cpp_gchandle_get_target( entity_list_hidden_value->_handle, &entity_list ) ) {
						sys::buffer_list<base_networkable*>* vals = entity_list->vals;
						// Validate that list is currently valid before we cache
						if ( vals ) {
							sys::array<base_networkable*>* buffer = vals->buffer;
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
			sys::list_dictionary<uint64_t, base_player*>* visible_player_list = nullptr;
			if ( il2cpp_gchandle_get_target( visible_player_list_hidden_value->_handle, &visible_player_list ) ) {
				sys::buffer_list<base_player*>* vals = visible_player_list->vals;
				// Validate that list is currently valid before we cache
				if ( vals ) {
					sys::array<base_player*>* buffer = vals->buffer;
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

struct cache_player_task {
	bool m_valid;
	model* m_model;
	sys::array<transform*>* m_bone_transforms_ptr;
	sys::array<transform*> m_bone_transforms_arr;
	transform* m_bone_transforms[ 128 ];
	unity::transform* m_internal_bone_transforms[ bone_count ];
};

struct update_player_task {
	bool m_valid;
	int m_maximum_index;
	unity::transform_access m_transform_accesses[ bone_count ];
	unity::math::trsx* m_p_local_transforms;
	fast_vector<unity::math::trsx> m_local_transforms;
	int* m_p_parent_indices;
	fast_vector<int> m_parent_indices;
};

cache_player_task* cache_player_tasks;
update_player_task* update_player_tasks;

#include "engine.h"

void update_bone_positions( fast_vector<player>& players, scatter_request* scatter ) {
	for ( int i = 0; i < players.size(); i++ ) {
		player* player = &players[ i ];
		update_player_task* task = &update_player_tasks[ i ];
		task->m_valid = player != nullptr;
		if ( !task->m_valid ) {
			continue;
		}

		for ( int j = 0; j < bone_count; j++ ) {
			scatter->add_field( &player->m_bone_transforms[ j ]->transform_data, &task->m_transform_accesses[ j ] );
		}
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 0; i < players.size(); i++ ) {
		update_player_task* task = &update_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		int max_index = 0;
		for ( int j = 0; j < bone_count; j++ ) {
			const unity::transform_access& transform_access = task->m_transform_accesses[ j ];

			if ( j == 0 ) {
				unity::transform_hierarchy* hierarchy = transform_access.hierarchy;
				if ( !hierarchy ) {
					task->m_valid = false;
					break;
				}

				scatter->add_field( &hierarchy->local_transforms, &task->m_p_local_transforms );
				scatter->add_field( &hierarchy->parent_indices, &task->m_p_parent_indices );
			}

			int index = transform_access.index;
			if ( index > max_index ) {
				max_index = index;
			}
		}

		task->m_maximum_index = max_index;
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 0; i < players.size(); i++ ) {
		update_player_task* task = &update_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		if ( !task->m_p_local_transforms || !task->m_p_parent_indices ) {
			task->m_valid = false;
			continue;
		}

		task->m_local_transforms.resize( task->m_maximum_index * 2 );
		task->m_parent_indices.resize( task->m_maximum_index * 2 );

		size_t local_transforms_size = ( task->m_maximum_index * sizeof( unity::math::trsx ) ) + sizeof( unity::math::trsx );
		size_t parent_indices_size = ( task->m_maximum_index * sizeof( int ) ) + sizeof( int );

		scatter->add_read( task->m_p_local_transforms, task->m_local_transforms.begin(), local_transforms_size );
		scatter->add_read( task->m_p_parent_indices, task->m_parent_indices.begin(), parent_indices_size );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 0; i < players.size(); i++ ) {
		player* player = &players[ i ];
		update_player_task* task = &update_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		unity::transform_internal batched = unity::transform_internal(
			&task->m_local_transforms, &task->m_parent_indices );

		for ( int j = 0; j < bone_count; j++ ) {
			player->m_bone_positions[ j ] = batched.get_position( task->m_transform_accesses[ j ].index );
		}
	}
}

void cache_players( scatter_request* scatter ) {
	auto [ count, buffer ] = cached_player_list->get();
	if ( !buffer || ( count < 0 || count > 1024 ) )
		return;

	base_player** base_players = buffer->read_all( count );
	if ( !base_players )
		return;

	for ( int i = 1; i < count; i++ ) {
		base_player* base_player = base_players[ i ];
		cache_player_task* task = &cache_player_tasks[ i ];
		task->m_valid = base_player != nullptr;
		if ( !task->m_valid ) {
			continue;
		}

		scatter->add_field( &base_player->model, &task->m_model );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		if ( !task->m_model ) {
			task->m_valid = false;
			continue;
		}

		scatter->add_field( &task->m_model->bone_transforms, &task->m_bone_transforms_ptr );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		if ( !task->m_bone_transforms_ptr ) {
			task->m_valid = false;
			continue;
		}

		scatter->add_read( task->m_bone_transforms_ptr, &task->m_bone_transforms_arr );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		uint64_t transform_count = task->m_bone_transforms_arr.size;
		if ( transform_count < 0 || transform_count > 128 ) {
			task->m_valid = false;
			continue;
		}

		scatter->add_read( task->m_bone_transforms_ptr->buffer, task->m_bone_transforms, transform_count * sizeof( transform* ) );
	}

	if ( scatter->dirty() && !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		for ( int j = 0; j < bone_count; j++ ) {
			transform* transform = task->m_bone_transforms[ skeleton_bones[ j ] ];
			if ( !transform )
				continue;

			scatter->add_field( &transform->cached_ptr, &task->m_internal_bone_transforms[ j ] );
		}
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	players* msg = new players;
	msg->m_type = message_type::players;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}
		
		player player;
		memcpy( player.m_bone_transforms, task->m_internal_bone_transforms, sizeof( player.m_bone_transforms ) );

		msg->m_players.push_back( player );

		LOG( "(%d) Pushed back %d\n", count, i );
	}

	update_bone_positions( msg->m_players, scatter );

	update_queue.push( msg );
	render_queue.push( msg );

	delete[] base_players;
}

void cache_thread() {
	cache_thread_running = true;

	cache_player_tasks = new cache_player_task[ 1024 ];
	update_player_tasks = new update_player_task[ 1024 ];

	scatter_request scatter;

	while ( true ) {
		if ( populate_entity_lists() ) {
			cache_players( &scatter );
		}

		Sleep( 1000 );
	}

	delete[] cache_player_tasks;
	delete[] update_player_tasks;
}