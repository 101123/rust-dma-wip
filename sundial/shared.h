#pragma once

#include "sdk.h"

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

struct player {
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
	fast_vector<player> m_players;
	fast_vector<player> m_scientists;
};

inline dro::SPSCQueue<message*, 16> render_queue;
inline dro::SPSCQueue<players*, 16> update_queue;