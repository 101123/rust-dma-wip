#pragma once

#include "sdk.h"
#include "assets.h"

#undef max
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

inline int skeleton_bones[] = {
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

#define bone_count _countof( skeleton_bones )

struct cached_belt_item {
	bool m_present;
	bool m_active;
	localized_item* m_localized_item;
	int m_amount;
};

struct cached_player {
	bool m_destroyed;
	bool m_initial_update;
	int m_player_flags;
	base_player* m_entity;
	uint64_t m_user_id;
	uint64_t m_team_id;
	sys::string m_name;
	cached_belt_item m_belt_items[ 6 ];
	unity::transform* m_bone_transforms[ bone_count ];
	vec3 m_bone_positions[ bone_count ];
};

enum class message_type : uint8_t {
	entities,
	players
};

struct message {
	message_type m_type;
};

struct entities : message {

};

struct players : message {
	players() {
		m_type = message_type::players;
	}

	fast_vector<cached_player> m_entities;
};

inline dro::SPSCQueue<message*, 16> render_queue;
inline dro::SPSCQueue<players*, 16> update_queue;