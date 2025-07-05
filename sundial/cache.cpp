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
		auto client_entities_hidden_value = base_networkable::s_static_fields->client_entities.value;
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
		auto visible_player_list_hidden_value = base_player::s_static_fields->visible_player_list.value;
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

struct item_data {
	item_definition* m_info;
	uint64_t m_uid;
	int m_amount;
	int m_position;
	int m_item_id;
};

struct cache_player_task {
	bool m_valid;
	bool m_is_player;
	il2cpp_class* m_klass;
	model* m_model;
	sys::string* m_name;
	sys::array<transform*>* m_bone_transforms_ptr;
	sys::array<transform*> m_bone_transforms_arr;
	transform* m_bone_transforms[ 128 ];
	unity::transform* m_internal_bone_transforms[ bone_count ];

	uint64_t m_active_item_id;

	hidden_value<player_inventory*, base_player::decrypt_inventory_handle>* m_inventory_hidden_value;
	uint32_t m_inventory_handle;
	player_inventory* m_inventory;

	item_container* m_belt;
	sys::list<item*>* m_item_list_ptr;
	sys::list<item*> m_item_list;

	item* m_items[ 6 ];
	item_data m_item_data[ 6 ];
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

cache_player_task cache_player_tasks[ 256 ];
util::tls<update_player_task[ 256 ], 2> update_player_task_tls;

#include "engine.h"

bool should_update_player( cached_player* player ) {
	if ( player->m_initial_update ) {
		return engine.w2s( &player->m_bone_positions[ 0 ] );
	}

	player->m_initial_update = true;
	return true;
}

void update_bone_positions( fast_vector<cached_player>& players, scatter_request* scatter ) {
	update_player_task* update_player_tasks = *update_player_task_tls.get();

	for ( int i = 0; i < players.size(); i++ ) {
		cached_player* player = &players[ i ];
		update_player_task* task = &update_player_tasks[ i ];
		task->m_valid = player != nullptr;
		if ( !task->m_valid ) {
			continue;
		}

		if ( !should_update_player( player ) ) {
			task->m_valid = false;
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
		cached_player* player = &players[ i ];
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
	uint64_t a = GetTickCount64();

	auto [ count, buffer ] = cached_player_list->get();
	if ( !buffer || ( count < 0 || count > 256 ) )
		return;

	base_player** base_players = buffer->read_all( count );
	if ( !base_players )
		return;

	players* msg = new players;
	if ( !msg )
		return;

	msg->m_entities.resize( count );

	// Zero out all data
	//
	for ( int i = 1; i < count; i++ ) {
		memset( &msg->m_entities[ i ], 0, sizeof( cached_player ) );
		memset( &cache_player_tasks[ i ], 0, sizeof( cache_player_task ) );
	}

	get_hidden_values_task hidden_values = {};

	for ( int i = 1; i < count; i++ ) {
		base_player* base_player = base_players[ i ];
		cached_player* player = &msg->m_entities[ i ];
		cache_player_task* task = &cache_player_tasks[ i ];
		task->m_valid = base_player != nullptr;
		if ( !task->m_valid ) {
			continue;
		}

		scatter->add_field( &base_player->klass, &task->m_klass );
		scatter->add_field( &base_player->model, &task->m_model );
		// lifestate
		// health
		// input
		// movement
		scatter->add_field( &base_player->current_team, &player->m_team_id );
		scatter->add_field( &base_player->active_item, &task->m_active_item_id );
		scatter->add_field( &base_player->player_flags, &player->m_player_flags );
		// eyes
		scatter->add_field( &base_player->user_id, &player->m_user_id );
		scatter->add_field( &base_player->inventory, &task->m_inventory_hidden_value );
		scatter->add_field( &base_player->display_name, &task->m_name );

		hidden_values.cache_gc_handles( scatter );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cached_player* player = &msg->m_entities[ i ];
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		// Check if we've had any bad reads
		//
		if ( !task->m_klass || !task->m_model || !task->m_inventory_hidden_value || !task->m_name ) {
			task->m_valid = false;
			continue;
		}

		// Normalize team id
		//
		if ( player->m_team_id < 0 || player->m_team_id > 65536 ) {
			player->m_team_id = 0;
		}

		// Decrypt encrypted values
		//
		base_player::decrypt_active_item( ( uint32_t* )&task->m_active_item_id );
		base_player::decrypt_user_id( ( uint32_t* )&player->m_user_id );

		// We only cache names of BasePlayer instances, scientists are just given their generic names, ex. ScientistNPC -> "Scientist", TunnelDweller -> "Tunnel Dweller"
		//
		if ( task->m_klass == base_player::s_klass ) {
			scatter->add_read( task->m_name, &player->m_name, sizeof( player->m_name ) );
		}

		scatter->add_field( &task->m_model->bone_transforms, &task->m_bone_transforms_ptr );
		scatter->add_field( &task->m_inventory_hidden_value->_handle, &task->m_inventory_handle );

		hidden_values.cache_entries( scatter );
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

		base_player::decrypt_inventory_handle( &task->m_inventory_handle );

		if ( !hidden_values.get( task->m_inventory_handle, &task->m_inventory ) ) {
			task->m_valid = false;
			continue;
		}
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

		if ( !task->m_inventory ) {
			task->m_valid = false;
			continue;
		}

		scatter->add_read( task->m_bone_transforms_ptr->buffer, task->m_bone_transforms, transform_count * sizeof( transform* ) );

		scatter->add_field( &task->m_inventory->container_belt, &task->m_belt );
	}

	if ( scatter->dirty() && !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		if ( !task->m_belt ) {
			task->m_valid = false;
			continue;
		}

		for ( int j = 0; j < bone_count; j++ ) {
			transform* transform = task->m_bone_transforms[ skeleton_bones[ j ] ];
			if ( !transform )
				continue;

			scatter->add_field( &transform->cached_ptr, &task->m_internal_bone_transforms[ j ] );
		}

		scatter->add_field( &task->m_belt->item_list, &task->m_item_list_ptr );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		if ( !task->m_item_list_ptr ) {
			task->m_valid = false;
			continue;
		}

		scatter->add_read( task->m_item_list_ptr, &task->m_item_list, sizeof( task->m_item_list ) );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		const sys::list<item*>& item_list = task->m_item_list;
		if ( !item_list.items || ( item_list.size <= 0 || item_list.size > 6 ) ) {
			task->m_valid = false;
			continue;
		}

		item_list.items->read_all( item_list.size, task->m_items, scatter );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		for ( int i = 0; i < task->m_item_list.size; i++ ) {
			item* item = task->m_items[ i ];
			if ( !item )
				continue;

			item_data* item_data = &task->m_item_data[ i ];

			scatter->add_field( &item->info, &item_data->m_info );
			scatter->add_field( &item->uid, &item_data->m_uid );
			scatter->add_field( &item->amount, &item_data->m_amount );
			scatter->add_field( &item->position, &item_data->m_position );
		}
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		for ( int i = 0; i < task->m_item_list.size; i++ ) {
			item_data* item_data = &task->m_item_data[ i ];
			if ( !item_data->m_info ) {
				continue;
			}

			scatter->add_field( &item_data->m_info->item_id, &item_data->m_item_id );
		}
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	// Finalize all data
	//
	for ( int i = 1; i < count; i++ ) {
		base_player* base_player = base_players[ i ];
		cached_player* player = &msg->m_entities[ i ];
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_valid ) {
			continue;
		}

		player->m_entity = base_player;

		for ( int i = 0; i < task->m_item_list.size; i++ ) {
			item_data* item_data = &task->m_item_data[ i ];

			player->m_belt_items[ item_data->m_position ] = cached_belt_item {
				.m_present = true,
				.m_active = item_data->m_uid == task->m_active_item_id,
				.m_localized_item = assets.get_localized_item( item_data->m_item_id ),
				.m_amount = item_data->m_amount
			};
		}
	}

	for ( int i = 1; i < count; i++ ) {
		cached_player* player = &msg->m_entities[ i ];

		LOG( "\n" );

		for ( int i = 0; i < 6; i++ ) {
			cached_belt_item* belt_item = &player->m_belt_items[ i ];
			if ( !belt_item->m_present )
				continue;

			if ( !belt_item->m_localized_item )
				continue;

			const char* status = belt_item->m_active ? "active" : "not active";

			LOG( "%d (%s) %s (%d)\n", i, status, belt_item->m_localized_item->m_translations[ 0 ].c_str(), belt_item->m_amount );
		}

		LOG( "\n" );
	}

	// LOG( "%llu\n", GetTickCount64() - a );

	delete[] base_players;
}

void cache_thread() {
	cache_thread_running = true;

	scatter_request scatter;

	while ( true ) {
		if ( populate_entity_lists() ) {
			cache_players( &scatter );
		}

		Sleep( 1000 );
	}

	cache_thread_running = false;
}