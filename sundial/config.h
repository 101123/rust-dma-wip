#pragma once

#include "util.h"
#include "renderer.h"

#include <cstdint>

template <typename T>
struct cvar_t {
	static inline cvar_t* s_instances[ 256 ];
	static inline int s_count;

	cvar_t( const cvar_t& ) = delete;
	cvar_t( cvar_t&& ) = delete;
	void operator=( const cvar_t& ) = delete;
	void operator=( cvar_t& ) = delete;

	cvar_t( uint64_t hash, T value = 0 ) : m_hash( hash ), m_value( value ), m_default_value( value ) {
		s_instances[ s_count++ ] = this;
	}

	T* operator&() {
		return &m_value;
	}

	cvar_t* operator*() {
		return this;
	}

	operator T() {
		return m_value;
	}

	T operator=( T value ) {
		return m_value = value;
	}

	uint64_t m_hash;
	T m_value;
	T m_default_value;
};

using cvar = cvar_t<bool>;
using cvar_i = cvar_t<int>;
using cvar_ui = cvar_t<unsigned int>;
using cvar_f = cvar_t<float>;

#define define_feature( name, variables ) \
    struct name##feature { \
        variables \
    }; \
    inline name##feature name;

struct visual {
	cvar m_enabled;
	cvar_i m_maximum_distance;
	cvar_ui m_color;
};

#define wrap_visual( name, enabled, maximum_distance, color ) { \
    cvar( H( name "_enabled" ), enabled ), \
	cvar_i( H( name "_maximum_distance" ), maximum_distance ), \
    cvar_ui( H( name "_color" ), color ) }

struct player_visuals {
	cvar m_enabled;
	cvar m_box;
	cvar_ui m_box_color;
	cvar m_skeleton;
	cvar_ui m_skeleton_color;
	cvar m_name;
	cvar_ui m_name_color;
	cvar m_distance;
	cvar_ui m_distance_color;
	cvar m_held_item;
	cvar_i m_held_item_type;
	cvar_ui m_held_item_color;
	cvar m_belt;
	cvar_i m_belt_type;
	cvar_i m_belt_fov;
	cvar_i m_maximum_distance;
};

#define wrap_player_visuals( name, color ) { \
	cvar( H( name "_enabled" ), true ), \
	cvar( H( name "_box" ), true ), \
	cvar_ui( H( name "_box_color" ), color ), \
	cvar( H( name "_skeleton" ), true ), \
	cvar_ui( H( name "_skeleton_color" ), color ), \
	cvar( H( name "_name" ), true ), \
	cvar_ui( H( name "_name_color" ), color ), \
	cvar( H( name "_distance" ), true ), \
	cvar_ui( H( name "_distance_color" ), color ), \
	cvar( H( name "_held_item" ), true ), \
	cvar_i( H( name "_held_item_type" ), 0 ), \
	cvar_ui( H( name "_held_item_color" ), color ), \
	cvar( H( name "_belt" ), true ), \
	cvar_i( H( name "_belt_type" ), 0 ), \
	cvar_i( H( name "_belt_fov" ), 200 ), \
	cvar_i( H( name "_maximum_distance" ), 500 ) }

inline player_visuals cvar_players = wrap_player_visuals( "players", col32( 255, 255, 255, 255 ) );
inline visual cvar_wounded = wrap_visual( "wounded", true, 500, col32( 255, 0, 0, 255 ) );
inline visual cvar_sleeper = wrap_visual( "sleeper", false, 30, col32( 255, 255, 255, 255 ) );
inline visual cvar_corpse = wrap_visual( "corpse", true, 100, col32( 255, 255, 255, 255 ) );

inline player_visuals cvar_scientists = wrap_player_visuals( "scientists", col32( 125, 195, 255, 255 ) );
