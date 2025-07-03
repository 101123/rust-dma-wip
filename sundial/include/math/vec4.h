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

	vec3 operator*( vec3 value ) {
		float x = this->x * 2.f;
		float y = this->y * 2.f;
		float z = this->z * 2.f;
		float xx = this->x * x;
		float yy = this->y * y;
		float zz = this->z * z;
		float xy = this->x * y;
		float xz = this->x * z;
		float yz = this->y * z;
		float wx = this->w * x;
		float wy = this->w * y;
		float wz = this->w * z;

		vec3 result;
		result.x = ( 1.f - ( yy + zz ) ) * value.x + ( xy - wz ) * value.y + ( xz + wy ) * value.z;
		result.y = ( xy + wz ) * value.x + ( 1.0f - ( xx + zz ) ) * value.y + ( yz - wx ) * value.z;
		result.z = ( xz - wy ) * value.x + ( yz + wx ) * value.y + ( 1.0f - ( xx + yy ) ) * value.z;

		return result;
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
