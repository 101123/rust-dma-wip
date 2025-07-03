#pragma once

class vec2 {
public:
	float x, y;

	vec2() : x( 0.f ), y( 0.f ) {};
	vec2( float _x, float _y ) : x( _x ), y( _y ) {};

	vec2 operator=( vec2 value ) {
		return vec2( this->x = value.x, this->y = value.y );
	}

	vec2 operator+( vec2 value ) {
		return vec2( this->x + value.x, this->y + value.y );
	}

	vec2 operator+( const vec2& value ) const {
		return vec2( this->x + value.x, this->y + value.y );
	}

	vec2& operator+=( const vec2& value ) {
		this->x += value.x; this->y += value.y; return *this;
	}

	vec2 operator-( vec2 value ) {
		return vec2( this->x - value.x, this->y - value.y );
	}

	vec2 operator-( const vec2& value ) const {
		return vec2( this->x - value.x, this->y - value.y );
	}

	vec2 operator*( float value ) const {
		return vec2( this->x * value, this->y * value );
	}

	vec2& operator*=( float value ) {
		this->x *= value; this->y *= value; return *this;
	}

	vec2 operator*( vec2 value ) {
		return vec2( this->x * value.x, this->y * value.y );
	}

	vec2 operator/( float value ) const {
		return vec2( this->x / value, this->y / value );
	}

	vec2 operator/( vec2 value ) {
		return vec2( this->x / value.x, this->y / value.y );
	}
};

class vec2i {
public:
	int x, y;

	vec2i() : x( 0 ), y( 0 ) {};
	vec2i( int _x, int _y ) : x( _x ), y( _y ) {};
};