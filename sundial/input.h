#pragma once

#include "sdk.h"

struct key_map {
	unity::dynamic_bitset m_bitset;
	fast_vector<uint32_t> m_bits;
};

class input_manager {
public:
	bool initialize() {
		return m_input_manager = unity::get_manager<unity::input_manager*>( unity::manager_type::input_manager );
	}

	void cache_input_fields( scatter_request* scatter ) {
		scatter->add_field( &m_input_manager->current_key_state, &m_current_key_state.m_bitset );
		scatter->add_field( &m_input_manager->this_frame_key_down, &m_this_frame_key_down.m_bitset );
		scatter->add_field( &m_input_manager->this_frame_key_up, &m_this_frame_key_up.m_bitset );
		scatter->add_field( &m_input_manager->mouse_delta, &m_mouse_delta );
		scatter->add_field( &m_input_manager->mouse_pos, &m_mouse_pos );
	}

	void cache_key_states( scatter_request* scatter ) {
		key_map* key_maps[] = {
			&m_current_key_state, &m_this_frame_key_down, &m_this_frame_key_up
		};

		for ( size_t i = 0; i < _countof( key_maps ); i++ ) {
			key_map* map = key_maps[ i ];

			map->m_bits.resize( map->m_bitset.m_num_bits );

			scatter->add_read( map->m_bitset.m_bits, map->m_bits.begin(), map->m_bitset.m_num_bits * sizeof( uint32_t ) );
		}
	}

	bool get_key( int key ) {
		return unity::dynamic_bitset::test( key, m_this_frame_key_down.m_bits ) ||
			unity::dynamic_bitset::test( key, m_current_key_state.m_bits );
	}

	bool get_key_down( int key ) {
		return unity::dynamic_bitset::test( key, m_this_frame_key_down.m_bits );
	}

	bool get_key_up( int key ) {
		return unity::dynamic_bitset::test( key, m_this_frame_key_up.m_bits );
	}

public:
	unity::input_manager* m_input_manager;

	key_map m_current_key_state;
	key_map m_this_frame_key_down;
	key_map m_this_frame_key_up;

	vec2 m_mouse_pos;
	vec4 m_mouse_delta;
};

inline input_manager input;