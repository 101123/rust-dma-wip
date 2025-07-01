#include "sdk.h"

float terrain_height_map::get_height( float norm_x, float norm_z, vec3 terrain_position, vec3 terrain_size, int res, uint16_t* height_map ) {
	return terrain_position.y + this->get_height_01( norm_x, norm_z, res, height_map ) * terrain_size.y;
}

float terrain_height_map::get_height_01( float norm_x, float norm_z, int res, uint16_t* height_map ) {
	int num = res - 1;
	float num2 = norm_x * ( float )num;
	float num3 = norm_z * ( float )num;
	int num4 = mathf::clamp( ( int )num2, 0, num );
	int num5 = mathf::clamp( ( int )num3, 0, num );
	int num6 = mathf::min( num4 + 1, num );
	int num7 = mathf::min( num5 + 1, num );
	float height = this->get_height_01( num4, num5, res, height_map );
	float height2 = this->get_height_01( num6, num5, res, height_map );
	float height3 = this->get_height_01( num4, num7, res, height_map );
	float height4 = this->get_height_01( num6, num7, res, height_map );
	float num8 = num2 - ( float )num4;
	float num9 = num3 - ( float )num5;
	float num10 = mathf::lerp( height, height2, num8 );
	float num11 = mathf::lerp( height3, height4, num8 );
	return mathf::lerp( num10, num11, num9 );
}

float terrain_height_map::get_height_01( int x, int z, int res, uint16_t* height_map ) {
	int index = z * res + x;
	return SHORT_TO_FLOAT( height_map[ index ] );
}

vec3 terrain_height_map::get_normal( float norm_x, float norm_z, int res, uint16_t* height_map, float norm_y ) {
	int num = res - 1;
	float num2 = norm_x * ( float )num;
	float num3 = norm_z * ( float )num;
	int num4 = mathf::clamp( ( int )num2, 0, num );
	int num5 = mathf::clamp( ( int )num3, 0, num );
	int num6 = mathf::min( num4 + 1, num );
	int num7 = mathf::min( num5 + 1, num );
	vec3 normal = this->get_normal( num4, num5, res, height_map, norm_y );
	vec3 normal2 = this->get_normal( num6, num5, res, height_map, norm_y );
	vec3 normal3 = this->get_normal( num4, num7, res, height_map, norm_y );
	vec3 normal4 = this->get_normal( num6, num7, res, height_map, norm_y );
	float num8 = num2 - ( float )num4;
	float num9 = num3 - ( float )num5;
	vec3 vector = Slerp( normal, normal2, num8 );
	vec3 vector2 = Slerp( normal3, normal4, num8 );
	return Normalize( Slerp( vector, vector2, num9 ) );
}

vec3 terrain_height_map::get_normal( int x, int z, int res, uint16_t* height_map, float normY ) {
	int num = res - 1;
	int num2 = mathf::clamp( x - 1, 0, num );
	int num3 = mathf::clamp( z - 1, 0, num );
	int num4 = mathf::clamp( x + 1, 0, num );
	int num5 = mathf::clamp( z + 1, 0, num );
	float num6 = ( this->get_height_01( num4, num3, res, height_map ) - this->get_height_01( num2, num3, res, height_map ) ) * 0.5f;
	float num7 = ( this->get_height_01( num2, num5, res, height_map ) - this->get_height_01( num2, num3, res, height_map ) ) * 0.5f;
	return Normalize( vec3( -num6, normY, -num7 ) );
}

float terrain_splat_map::get_splat( float norm_x, float norm_z, int mask, int res, uint8_t* splat_map ) {
	int num = res - 1;
	float num2 = norm_x * ( float )num;
	float num3 = norm_z * ( float )num;
	int num4 = mathf::clamp( ( int )num2, 0, num );
	int num5 = mathf::clamp( ( int )num3, 0, num );
	int num6 = mathf::min( num4 + 1, num );
	int num7 = mathf::min( num5 + 1, num );
	float num8 = mathf::lerp( this->get_splat( num4, num5, mask, res, splat_map ), this->get_splat( num6, num5, mask, res, splat_map ), num2 - ( float )num4 );
	float num9 = mathf::lerp( this->get_splat( num4, num7, mask, res, splat_map ), this->get_splat( num6, num7, mask, res, splat_map ), num2 - ( float )num4 );
	return mathf::lerp( num8, num9, num3 - ( float )num5 );
}

float terrain_splat_map::get_splat( int x, int z, int mask, int res, uint8_t* splat_map ) {
	int index = ( mask * res + z ) * res + x;
	return BYTE_TO_FLOAT( splat_map[ index ] );
}

int terrain_topology_map::get_topology( float norm_x, float norm_z, float radius, vec3 terrain_one_over_size, int res, int32_t* topology_map ) {
	int num = 0;
	float num2 = terrain_one_over_size.x * radius;
	float num3 = radius * radius;
	int num4 = this->index( norm_x, res );
	int num5 = this->index( norm_z, res );
	int num6 = this->index( norm_x - num2, res );
	int num7 = this->index( norm_x + num2, res );
	int num8 = this->index( norm_z - num2, res );
	int num9 = this->index( norm_z + num2, res );
	for ( int i = num8; i <= num9; i++ ) {
		int num10 = i - num5;
		int num11 = num10 * num10;
		for ( int j = num6; j <= num7; j++ ) {
			int num12 = j - num4;
			if ( ( float )( num12 * num12 + num11 ) <= num3 ) {
				num |= topology_map[ i * res + j ];
			}
		}
	}
	return num;
}

std::pair<vec3, float> terrain_texturing::get_coarse_vector_to_shore( vec2 uv, int shore_map_size, vec4* shore_vectors, float shore_distance_scale ) {
	int num = shore_map_size;
	int num2 = num - 1;
	float num3 = uv.x * ( float )num2;
	float num4 = uv.y * ( float )num2;
	int num5 = ( int )num3;
	int num6 = ( int )num4;
	float num7 = num3 - ( float )num5;
	float num8 = num4 - ( float )num6;
	num5 = ( ( num5 >= 0 ) ? num5 : 0 );
	num6 = ( ( num6 >= 0 ) ? num6 : 0 );
	num5 = ( ( num5 <= num2 ) ? num5 : num2 );
	num6 = ( ( num6 <= num2 ) ? num6 : num2 );
	int num9 = ( ( num3 < ( float )num2 ) ? 1 : 0 );
	int num10 = ( ( num4 < ( float )num2 ) ? num : 0 );
	int num11 = num6 * num + num5;
	int num12 = num11 + num9;
	int num13 = num11 + num10;
	int num14 = num13 + num9;
	vec4 xyz = shore_vectors[ num11 ];
	vec4 xyz2 = shore_vectors[ num12 ];
	vec4 xyz3 = shore_vectors[ num13 ];
	vec4 xyz4 = shore_vectors[ num14 ];
	vec3 vector;
	vector.x = ( xyz2.x - xyz.x ) * num7 + xyz.x;
	vector.y = ( xyz2.y - xyz.y ) * num7 + xyz.y;
	vector.z = ( xyz2.z - xyz.z ) * num7 + xyz.z;
	vec3 vector2;
	vector2.x = ( xyz4.x - xyz3.x ) * num7 + xyz3.x;
	vector2.y = ( xyz4.y - xyz3.y ) * num7 + xyz3.y;
	vector2.z = ( xyz4.z - xyz3.z ) * num7 + xyz3.z;
	float num15 = ( vector2.x - vector.x ) * num8 + vector.x;
	float num16 = ( vector2.y - vector.y ) * num8 + vector.y;
	float num17 = ( vector2.z - vector.z ) * num8 + vector.z;
	return { vec3( num15, 0.f, num16 ), num17 * shore_distance_scale };
}