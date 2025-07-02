#pragma once

#include "sdk.h"
#include "shared.h"

class unity_engine {
public:
	bool w2s( vec3* world, vec2* screen );
	bool w2s( vec3* world );

	vec3 cam_pos() {
		return m_cam_pos;
	}

	void update( scatter_request* scatter );

	unity::camera* m_camera;
	mat4x4 m_view_matrix;
	vec3 m_cam_pos;
};

inline unity_engine engine;
