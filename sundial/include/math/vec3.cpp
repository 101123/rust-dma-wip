#include "vec3.h"
#include "mat3x3.h"

const float vec3::epsilon = 0.00001f;

vec3 ortho_normal_vector_fast( const vec3& n ) {
	if ( fabsf( n.z ) > 0.7071067811865475244008443621048490f ) {
		float a = n.y * n.y + n.z * n.z;
		float k = 1.f / sqrtf( a );
		return vec3( 0.f, -n.z * k, n.y * k );
	}

	else {
		float a = n.x * n.x + n.y * n.y;
		float k = 1.f / sqrtf( a );
		return vec3( -n.y * k, n.x * k, 0.f );
	}
}

vec3 slerp( const vec3& lhs, const vec3& rhs, float t ) {
	float lhs_mag = magnitude( lhs );
	float rhs_mag = magnitude( rhs );
	if ( lhs_mag < vec3::epsilon || rhs_mag < vec3::epsilon )
		return lerp( lhs, rhs, t );

	float lerped_mag = lerp( lhs_mag, rhs_mag, t );
	float dir = dot( lhs, rhs ) / ( lhs_mag * rhs_mag );
	if ( dir > 1.f - vec3::epsilon ) {
		return lerp( lhs, rhs, t );
	}

	else if ( dir < -1.f + vec3::epsilon ) {
		vec3 lhs_norm = lhs / lhs_mag;
		vec3 axis = ortho_normal_vector_fast( lhs_norm );
		mat3x3 m;
		m.set_axis_angle( axis, 3.14159265358979323846264338327950288419716939937510f * t );
		vec3 slerped = m.multiply( lhs_norm );
		slerped *= lerped_mag;
		return slerped;
	}

	else {
		vec3 axis = cross( lhs, rhs );
		vec3 lhs_norm = lhs / lhs_mag;
		axis = normalize( axis );
		float angle = acosf( dir ) * t;
		mat3x3 m;
		m.set_axis_angle( axis, angle );
		vec3 slerped = m.multiply( lhs_norm );
		slerped *= lerped_mag;
		return slerped;
	}
}