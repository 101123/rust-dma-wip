#pragma once

#include "common.h"

class vec3 {
public:
	float x, y, z;

	vec3() : x( 0.f ), y( 0.f ), z( 0.f ) {};
	vec3( float _x, float _y, float _z ) : x( _x ), y( _y ), z( _z ) {};

	float* get_ptr() {
		return &x;
	}

	const float* get_ptr() const {
		return &x;
	}

	vec3& operator+=( const vec3& value ) {
		x += value.x; y += value.y; z += value.z; return *this; 
	}

	vec3& operator-=( const vec3& value ) {
		x -= value.x; y -= value.y; z -= value.z; return *this; 
	}

	vec3& operator*=( float value ) { 
		x *= value; y *= value; z *= value; return *this; 
	}

	vec3& operator/=( float value ) {
		x /= value; y /= value; z /= value; return *this;
	}

	static const float epsilon;
};

inline vec3 operator+( const vec3& lhs, const vec3& rhs ) { 
	return vec3( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z );
}

inline vec3 operator-( const vec3& lhs, const vec3& rhs ) { 
	return vec3( lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z );
}

inline vec3 operator*( const vec3& lhs, const float rhs ) { 
	return vec3( lhs.x * rhs, lhs.y * rhs, lhs.z * rhs );
}

inline vec3 operator*( const float lhs, const vec3& rhs ) {
	return vec3( rhs.x * lhs, rhs.y * lhs, rhs.z * lhs );
}

inline vec3 operator*( const vec3& lhs, const vec3& rhs ) {
	return vec3( lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z );
}

inline vec3 operator/( const vec3& lhs, const float rhs ) {
	vec3 vec( lhs ); vec /= rhs; return vec;
}

inline vec3 cross( const vec3& lhs, const vec3& rhs ) {
	return vec3( 
		lhs.y * rhs.z - lhs.z * rhs.y, 
		lhs.z * rhs.x - lhs.x * rhs.z, 
		lhs.x * rhs.y - lhs.y * rhs.x 
	);
}

inline float dot( const vec3& lhs, const vec3& rhs ) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; 
}

inline float sqr_magnitude( const vec3& vec ) {
	return dot( vec, vec );
}

inline float magnitude( const vec3& vec ) {
	return sqrtf( dot( vec, vec ) );
}

inline float distance( const vec3& lhs, const vec3& rhs ) {
	return magnitude( lhs - rhs );
}

inline float sqr_distance( const vec3& lhs, const vec3& rhs ) {
	return sqr_magnitude( lhs - rhs );
}

inline vec3 normalize( const vec3& vec ) {
	return vec / magnitude( vec );
}

inline float angle( const vec3& lhs, const vec3& rhs ) {
	return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
}

inline vec3 lerp( const vec3& from, const vec3& to, float t ) { 
	return to * t + from * ( 1.f - t ); 
}

vec3 ortho_normal_vector_fast( const vec3& n );
vec3 slerp( const vec3& lhs, const vec3& rhs, float t );

