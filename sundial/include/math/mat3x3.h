#pragma once

#include "vec3.h"

class mat3x3 {
public:
	union {
		float data[ 3 * 3 ];
		vec3 vec[ 3 ];
	};

	mat3x3() {};
	mat3x3( vec3 a, vec3 b, vec3 c ) {
		vec[ 0 ] = a;
		vec[ 1 ] = b;
		vec[ 2 ] = c;
	}

	float& get( int row, int column ) { 
		return data[ row + ( column * 3 ) ]; 
	}

	const float& get( int row, int column ) const { 
		return data[ row + ( column * 3 ) ]; 
	}

	float operator[]( int index ) const {
		return data[ index ];
	}

	float& operator[]( int index ) {
		return data[ index ];
	}

	vec3 multiply( const vec3& v ) const {
		vec3 res;
		res.x = data[ 0 ] * v.x + data[ 3 ] * v.y + data[ 6 ] * v.z;
		res.y = data[ 1 ] * v.x + data[ 4 ] * v.y + data[ 7 ] * v.z;
		res.z = data[ 2 ] * v.x + data[ 5 ] * v.y + data[ 8 ] * v.z;
		return res;
	}

	mat3x3& set_axis_angle( const vec3& rotation_axis, float radians );
};