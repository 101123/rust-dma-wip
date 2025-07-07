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

template <typename T>
struct hidden_value_data {
	uint32_t m_handle;
	T m_value;
};

template <typename T>
struct mem_ref {
	T* m_ptr;
	T m_value;
};

struct cache_player_task {
	bool m_continue;

	il2cpp_class* m_klass;
	model* m_model;

	player_model* m_player_model;
	uint64_t m_team_id;
	uint64_t m_active_item_id;
	int m_player_flags;

	uint64_t m_user_id;
	hidden_value<player_inventory*, base_player::decrypt_inventory_handle>* m_inventory_hidden_value;
	mem_ref<sys::string> m_name;

	vec3 m_position;
	mem_ref<sys::array<transform*>> m_bone_transforms;

	transform* m_transforms[ 128 ];
	unity::transform* m_internal_transforms[ bone_count ];


	hidden_value_data<player_inventory*> m_inventory;

	item_container* m_belt;
	mem_ref<sys::list<item*>> m_item_list;

	item* m_items[ 6 ];
	item_data m_item_data[ 6 ];
};

struct update_player_task {
	bool m_continue;
	bool m_relative_update;
	vec3 m_base_position;

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

enum player_update_type {
	no_update,
	relative_update,
	full_update
};

player_update_type get_player_update_type( cached_player* player ) {
	vec3& bottom_world = player->m_bone_positions[ 17 ];
	vec3 top_world = bottom_world + vec3( 0.f, 1.8f, 0.f );
	vec2 bottom_screen, top_screen;
	if ( !engine.w2s( &bottom_world, &bottom_screen ) || !engine.w2s( &top_world, &top_screen ) )
		return no_update;

	float delta = bottom_screen.y - top_screen.y;
	return delta < 10.f ? relative_update : full_update;
}

void update_bone_positions( fast_vector<cached_player>& players, scatter_request* scatter, bool initial_update = false ) {
	update_player_task* update_player_tasks = *update_player_task_tls.get();

	for ( int i = 0; i < players.size(); i++ ) {
		update_player_task* task = &update_player_tasks[ i ];

		task->m_relative_update = false;
		task->m_base_position = vec3();
		task->m_maximum_index = -1;
		task->m_p_local_transforms = nullptr;
		task->m_p_parent_indices = nullptr;
	}

	for ( int i = 0; i < players.size(); i++ ) {
		cached_player* player = &players[ i ];
		update_player_task* task = &update_player_tasks[ i ];
		task->m_continue = player != nullptr;
		if ( !task->m_continue )
			continue;

		if ( !initial_update ) {
			player_update_type update_type = get_player_update_type( player );
			if ( update_type == no_update ) {
				task->m_continue = false;
				continue;
			}

			if ( update_type == relative_update ) {
				task->m_relative_update = true;
			}
		}

		scatter->add_field( &player->m_player_model->position, &task->m_base_position );

		if ( !task->m_relative_update ) {
			for ( int j = 0; j < bone_count; j++ ) {
				scatter->add_field( &player->m_bone_transforms[ j ]->transform_data, &task->m_transform_accesses[ j ] );
			}
		}
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 0; i < players.size(); i++ ) {
		cached_player* player = &players[ i ];
		update_player_task* task = &update_player_tasks[ i ];
		if ( !task->m_continue ) 
			continue;

		if ( task->m_relative_update ) {
			for ( int j = 0; j < bone_count; j++ ) {
				player->m_bone_positions[ j ] = task->m_base_position + player->m_relative_bone_positions[ j ];
			}

			task->m_continue = false;
			continue;
		}

		int max_index = 0;
		for ( int k = 0; k < bone_count; k++ ) {
			const unity::transform_access& transform_access = task->m_transform_accesses[ k ];

			if ( k == 0 ) {
				unity::transform_hierarchy* hierarchy = transform_access.hierarchy;
				if ( !hierarchy ) {
					task->m_continue = false;
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
		if ( !task->m_continue ) 
			continue;

		if ( !task->m_p_local_transforms || !task->m_p_parent_indices || 
			( task->m_maximum_index <= 0 || task->m_maximum_index > 65536 ) ) {
			task->m_continue = false;
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
		if ( !task->m_continue ) 
			continue;

		unity::transform_internal batched = unity::transform_internal(
			&task->m_local_transforms, &task->m_parent_indices );

		for ( int j = 0; j < bone_count; j++ ) {
			player->m_bone_positions[ j ] = batched.get_position( task->m_transform_accesses[ j ].index );
			player->m_relative_bone_positions[ j ] = player->m_bone_positions[ j ] - task->m_base_position;
		}
	}
}

void cache_players( scatter_request* scatter ) {
	auto [ count, buffer ] = cached_player_list->get();
	if ( !buffer || ( count < 0 || count > 256 ) )
		return;

	base_player** base_players = buffer->read_all( count );
	if ( !base_players )
		return;

	for ( int i = 0; i < count; i++ ) {
		memset( &cache_player_tasks[ i ], 0, sizeof( cache_player_task ) );
	}

	get_hidden_values_task hidden_values = {};

	for ( int i = 1; i < count; i++ ) {
		base_player* base_player = base_players[ i ];
		cache_player_task* task = &cache_player_tasks[ i ];
		task->m_continue = base_player != nullptr;
		if ( !task->m_continue )
			continue;

		scatter->add_field( &base_player->klass, &task->m_klass );
		scatter->add_field( &base_player->model, &task->m_model );
		// lifestate
		// health
		// input
		// movement
		scatter->add_field( &base_player->player_model, &task->m_player_model );
		scatter->add_field( &base_player->current_team, &task->m_team_id );
		scatter->add_field( &base_player->cl_active_item, &task->m_active_item_id );
		scatter->add_field( &base_player->player_flags, &task->m_player_flags );
		// eyes
		scatter->add_field( &base_player->user_id, &task->m_user_id );
		scatter->add_field( &base_player->inventory, &task->m_inventory_hidden_value );
		scatter->add_field( &base_player->display_name, &task->m_name.m_ptr );

		hidden_values.cache_gc_handles( scatter );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		if ( !task->m_klass || !task->m_model || !task->m_player_model || !task->m_inventory_hidden_value || !task->m_name.m_ptr ) {
			task->m_continue = false;
			continue;
		}

		task->m_team_id = ( task->m_team_id < 0 || task->m_team_id > 65536 ) ? 0 : task->m_team_id;

		base_player::decrypt_cl_active_item( ( uint32_t* )&task->m_active_item_id );
		base_player::decrypt_user_id( ( uint32_t* )&task->m_user_id );

		scatter->add_field( &task->m_model->bone_transforms, &task->m_bone_transforms.m_ptr );
		scatter->add_field( &task->m_player_model->position, &task->m_position );
		scatter->add_field( &task->m_inventory_hidden_value->_handle, &task->m_inventory.m_handle );

		if ( task->m_klass == base_player::s_klass ) {
			scatter->add_read( task->m_name.m_ptr, &task->m_name.m_value, sizeof( task->m_name.m_value ) );
		}

		hidden_values.cache_entries( scatter );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		if ( !task->m_bone_transforms.m_ptr ) {
			task->m_continue = false;
			continue;
		}

		base_player::decrypt_inventory_handle( ( uint32_t* )&task->m_inventory.m_handle );

		if ( !hidden_values.get( task->m_inventory.m_handle, &task->m_inventory.m_value ) ) {
			task->m_continue = false;
			continue;
		}

		scatter->add_read( task->m_bone_transforms.m_ptr, &task->m_bone_transforms.m_value );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		uint64_t transform_count = task->m_bone_transforms.m_value.size;
		if ( transform_count < 0 || transform_count > 128 ) {
			task->m_continue = false;
			continue;
		}

		scatter->add_read( task->m_bone_transforms.m_ptr->buffer, task->m_transforms, transform_count * sizeof( transform* ) );
		scatter->add_field( &task->m_inventory.m_value->container_belt, &task->m_belt );
	}

	if ( scatter->dirty() && !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		if ( !task->m_belt ) {
			task->m_continue = false;
			continue;
		}

		bool any_failed = false;

		for ( int j = 0; j < bone_count; j++ ) {
			transform* transform = task->m_transforms[ skeleton_bones[ j ] ];
			if ( !transform ) {
				any_failed = true;
				break;
			}

			scatter->add_field( &transform->cached_ptr, &task->m_internal_transforms[ j ] );
		}

		if ( any_failed ) {
			task->m_continue = false;
			continue;
		}

		scatter->add_field( &task->m_belt->item_list, &task->m_item_list.m_ptr );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;
		
		if ( !task->m_item_list.m_ptr ) {
			task->m_continue = false;
			continue;
		}

		scatter->add_read( task->m_item_list.m_ptr, &task->m_item_list.m_value, sizeof( task->m_item_list.m_value ) );
	}

	if ( !scatter->dirty() || !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		const sys::list<item*>& item_list = task->m_item_list.m_value;
		if ( !item_list.items || ( item_list.size < 0 || item_list.size > 6 ) ) {
			task->m_continue = false;
			continue;
		}

		if ( item_list.size != 0 ) {
			item_list.items->read_all( item_list.size, task->m_items, scatter );
		}
	}

	if ( scatter->dirty() && !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		bool any_failed = false;

		for ( int i = 0; i < task->m_item_list.m_value.size; i++ ) {
			item* item = task->m_items[ i ];
			if ( !item ) {
				any_failed = true;
				break;
			}

			item_data* item_data = &task->m_item_data[ i ];

			scatter->add_field( &item->info, &item_data->m_info );
			scatter->add_field( &item->uid, &item_data->m_uid );
			scatter->add_field( &item->amount, &item_data->m_amount );
			scatter->add_field( &item->position, &item_data->m_position );
		}

		if ( any_failed ) {
			task->m_continue = false;
			continue;
		}
	}

	if ( scatter->dirty() && !scatter->execute_and_clear() )
		return;

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		bool any_failed = false;

		for ( int i = 0; i < task->m_item_list.m_value.size; i++ ) {
			item_data* item_data = &task->m_item_data[ i ];
			if ( !item_data->m_info ) {
				any_failed = true;
				break;
			}

			scatter->add_field( &item_data->m_info->item_id, &item_data->m_item_id );
		}

		if ( any_failed ) {
			task->m_continue = false;
			continue;
		}
	}

	if ( scatter->dirty() && !scatter->execute_and_clear() )
		return;

	players* msg = new players;
	if ( !msg ) {
		delete[] base_players;
		return;
	}

	msg->m_entities.reserve( count );

	for ( int i = 1; i < count; i++ ) {
		cache_player_task* task = &cache_player_tasks[ i ];
		if ( !task->m_continue )
			continue;

		cached_player* player = msg->m_entities.push_back();

		player->m_destroyed = false;
		player->m_klass = task->m_klass;
		player->m_player_model = task->m_player_model;
		player->m_player_flags = task->m_player_flags;
		player->m_team_id = task->m_team_id;
		player->m_user_id = task->m_user_id;

		if ( player->m_klass == base_player::s_klass ) {
			memcpy( &player->m_name, &task->m_name.m_value, sizeof( task->m_name.m_value ) );
		} else if ( player->m_klass == scientist_npc::s_klass ) {
			wcscpy_s( player->m_name.str, sizeof( player->m_name.str ), L"Scientist" );
		} else if ( player->m_klass == tunnel_dweller::s_klass ) {
			wcscpy_s( player->m_name.str, sizeof( player->m_name.str ), L"Tunnel Dweller" );
		} else if ( player->m_klass == underwater_dweller::s_klass ) {
			wcscpy_s( player->m_name.str, sizeof( player->m_name.str ), L"Underwater Dweller" );
		} else if ( player->m_klass == scarecrow_npc::s_klass ) {
			wcscpy_s( player->m_name.str, sizeof( player->m_name.str ), L"Scarecrow" );
		} else if ( player->m_klass == gingerbread_npc::s_klass ) {
			wcscpy_s( player->m_name.str, sizeof( player->m_name.str ), L"Gingerbread" );
		}

		memset( &player->m_belt_items, 0, sizeof( player->m_belt_items ) );

		for ( int j = 0; j < task->m_item_list.m_value.size; j++ ) {
			item_data* item_data = &task->m_item_data[ j ];

			player->m_belt_items[ item_data->m_position ] = cached_belt_item {
				.m_present = true,
				.m_active = item_data->m_uid == task->m_active_item_id,
				.m_localized_item = assets.get_localized_item( item_data->m_item_id ),
				.m_amount = item_data->m_amount
			};
		}

		memcpy( &player->m_bone_transforms, &task->m_internal_transforms, sizeof( player->m_bone_transforms ) );
	}

	update_bone_positions( msg->m_entities, scatter, true );

	update_queue.push( msg );
	render_queue.push( msg );

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