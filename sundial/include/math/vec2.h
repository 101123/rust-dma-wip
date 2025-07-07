#pragma once

#include "common.h"

class vec2 {
public:
	float x, y;

	vec2() : x( 0.f ), y( 0.f ) {};
	vec2( float _x, float _y ) : x( _x ), y( _y ) {};

	vec2& operator+=( const vec2& value ) {
		x += value.x; y += value.y; return *this;
	}

	vec2& operator-=( const vec2& value ) {
		x -= value.x; y -= value.y; return *this;
	}

	vec2& operator*=( float value ) {
		x *= value; y *= value; return *this;
	}

	vec2& operator/=( float value ) {
		x /= value; y /= value; return *this;
	}
};

inline vec2 operator+( const vec2& lhs, const vec2& rhs ) {
	return vec2( lhs.x + rhs.x, lhs.y + rhs.y );
}

inline vec2 operator-( const vec2& lhs, const vec2& rhs ) {
	return vec2( lhs.x - rhs.x, lhs.y - rhs.y );
}

inline vec2 operator*( const vec2& lhs, const float rhs ) {
	return vec2( lhs.x * rhs, lhs.y * rhs );
}

inline vec2 operator*( const float lhs, const vec2& rhs ) {
	return vec2( rhs.x * lhs, rhs.y * lhs );
}

inline vec2 operator*( const vec2& lhs, const vec2& rhs ) {
	return vec2( lhs.x * rhs.x, lhs.y * rhs.y );
}

inline vec2 operator/( const vec2& lhs, const float rhs ) {
	vec2 vec( lhs ); vec /= rhs; return vec;
}

inline float dot( const vec2& lhs, const vec2& rhs ) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline float sqr_magnitude( const vec2& vec ) {
	return dot( vec, vec );
}

inline float magnitude( const vec2& vec ) {
	return sqrtf( dot( vec, vec ) );
}

inline float distance( const vec2& lhs, const vec2& rhs ) {
	return magnitude( lhs - rhs );
}

inline float sqr_distance( const vec2& lhs, const vec2& rhs ) {
	return sqr_magnitude( lhs - rhs );
}

inline vec2 normalize( const vec2& vec ) {
	return vec / magnitude( vec );
}

inline float angle( const vec2& lhs, const vec2& rhs ) {
	return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
}

inline vec2 lerp( const vec2& from, const vec2& to, float t ) {
	return to * t + from * ( 1.f - t );
}

class vec2i {
public:
	int x, y;

	vec2i() : x( 0 ), y( 0 ) {};
	vec2i( int _x, int _y ) : x( _x ), y( _y ) {};
};