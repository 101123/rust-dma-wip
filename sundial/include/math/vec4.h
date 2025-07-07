#pragma once

#include "vec3.h"

class vec4 {
public:
	float x, y, z, w;

	vec4() : x( 0.f ), y( 0.f ), z( 0.f ), w( 0.f ) {};
	vec4( float _x, float _y, float _z, float _w ) : x( _x ), y( _y ), z( _z ), w( _w ) {};

	float* get_ptr() {
		return &x;
	}

	const float* get_ptr() const {
		return &x;
	}
};

inline vec4 operator*( const vec4& lhs, const vec4& rhs ) {
	return vec4( lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w );
}

inline vec4 operator*( const vec4& lhs, const float rhs ) {
	return vec4( lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs );
}

inline vec4 operator+( const vec4& lhs, const vec4& rhs ) {
	return vec4( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w );
}

inline vec4 operator-( const vec4& lhs, const vec4& rhs ) {
	return vec4( lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w );
}

inline vec4 lerp( const vec4& from, const vec4& to, float t ) {
	return to * t + from * ( 1.f - t );
}

class vec4i {
public:
	int x, y, z, w;

	vec4i() : x( 0 ), y( 0 ), z( 0 ), w( 0 ) {};
	vec4i( int _x, int _y, int _z, int _w ) : x( _x ), y( _y ), z( _z ), w( _w ) {};
};