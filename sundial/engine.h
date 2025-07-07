#pragma once

#include "sdk.h"
#include "shared.h"

class engine_manager {
public:
	void update( scatter_request* scatter );

	bool w2s( vec3* world, vec2* screen );
	bool w2s( vec3* world );

	unity::camera* m_camera;
	mat4x4 m_view_matrix;
	vec3 m_camera_position;
	vec3 m_camera_forward;
	float m_camera_yaw;
};

inline engine_manager engine;
