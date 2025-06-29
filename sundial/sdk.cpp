#include "sdk.h"

float TerrainHeightMap::GetHeight( float normX, float normZ, Vector3 terrainPosition, Vector3 terrainSize, int res, uint16_t* heightMap ) {
	return terrainPosition.y + this->GetHeight01( normX, normZ, res, heightMap ) * terrainSize.y;
}

float TerrainHeightMap::GetHeight01( float normX, float normZ, int res, uint16_t* heightMap ) {
	int num = res - 1;
	float num2 = normX * ( float )num;
	float num3 = normZ * ( float )num;
	int num4 = Mathf::Clamp( ( int )num2, 0, num );
	int num5 = Mathf::Clamp( ( int )num3, 0, num );
	int num6 = Mathf::Min( num4 + 1, num );
	int num7 = Mathf::Min( num5 + 1, num );
	float height = this->GetHeight01( num4, num5, res, heightMap );
	float height2 = this->GetHeight01( num6, num5, res, heightMap );
	float height3 = this->GetHeight01( num4, num7, res, heightMap );
	float height4 = this->GetHeight01( num6, num7, res, heightMap );
	float num8 = num2 - ( float )num4;
	float num9 = num3 - ( float )num5;
	float num10 = Mathf::Lerp( height, height2, num8 );
	float num11 = Mathf::Lerp( height3, height4, num8 );
	return Mathf::Lerp( num10, num11, num9 );
}

float TerrainHeightMap::GetHeight01( int x, int z, int res, uint16_t* heightMap ) {
	int index = z * res + x;
	return SHORT_TO_FLOAT( heightMap[ index ] );
}

Vector3 TerrainHeightMap::GetNormal( float normX, float normZ, int res, uint16_t* heightMap, float normY ) {
	int num = res - 1;
	float num2 = normX * ( float )num;
	float num3 = normZ * ( float )num;
	int num4 = Mathf::Clamp( ( int )num2, 0, num );
	int num5 = Mathf::Clamp( ( int )num3, 0, num );
	int num6 = Mathf::Min( num4 + 1, num );
	int num7 = Mathf::Min( num5 + 1, num );
	Vector3 normal = this->GetNormal( num4, num5, res, heightMap, normY );
	Vector3 normal2 = this->GetNormal( num6, num5, res, heightMap, normY );
	Vector3 normal3 = this->GetNormal( num4, num7, res, heightMap, normY );
	Vector3 normal4 = this->GetNormal( num6, num7, res, heightMap, normY );
	float num8 = num2 - ( float )num4;
	float num9 = num3 - ( float )num5;
	Vector3 vector = Slerp( normal, normal2, num8 );
	Vector3 vector2 = Slerp( normal3, normal4, num8 );
	return Normalize( Slerp( vector, vector2, num9 ) );
}

Vector3 TerrainHeightMap::GetNormal( int x, int z, int res, uint16_t* heightMap, float normY ) {
	int num = res - 1;
	int num2 = Mathf::Clamp( x - 1, 0, num );
	int num3 = Mathf::Clamp( z - 1, 0, num );
	int num4 = Mathf::Clamp( x + 1, 0, num );
	int num5 = Mathf::Clamp( z + 1, 0, num );
	float num6 = ( this->GetHeight01( num4, num3, res, heightMap ) - this->GetHeight01( num2, num3, res, heightMap ) ) * 0.5f;
	float num7 = ( this->GetHeight01( num2, num5, res, heightMap ) - this->GetHeight01( num2, num3, res, heightMap ) ) * 0.5f;
	return Normalize( Vector3( -num6, normY, -num7 ) );
}

float TerrainSplatMap::GetSplat( float normX, float normZ, int mask, int res, uint8_t* splatMap ) {
	int num = res - 1;
	float num2 = normX * ( float )num;
	float num3 = normZ * ( float )num;
	int num4 = Mathf::Clamp( ( int )num2, 0, num );
	int num5 = Mathf::Clamp( ( int )num3, 0, num );
	int num6 = Mathf::Min( num4 + 1, num );
	int num7 = Mathf::Min( num5 + 1, num );
	float num8 = Mathf::Lerp( this->GetSplat( num4, num5, mask, res, splatMap ), this->GetSplat( num6, num5, mask, res, splatMap ), num2 - ( float )num4 );
	float num9 = Mathf::Lerp( this->GetSplat( num4, num7, mask, res, splatMap ), this->GetSplat( num6, num7, mask, res, splatMap ), num2 - ( float )num4 );
	return Mathf::Lerp( num8, num9, num3 - ( float )num5 );
}

float TerrainSplatMap::GetSplat( int x, int z, int mask, int res, uint8_t* splatMap ) {
	int index = ( mask * res + z ) * res + x;
	return BYTE_TO_FLOAT( splatMap[ index ] );
}

int TerrainTopologyMap::GetTopology( float normX, float normZ, float radius, Vector3 terrainOneOverSize, int res, int32_t* topologyMap ) {
	int num = 0;
	float num2 = terrainOneOverSize.x * radius;
	float num3 = radius * radius;
	int num4 = this->Index( normX, res );
	int num5 = this->Index( normZ, res );
	int num6 = this->Index( normX - num2, res );
	int num7 = this->Index( normX + num2, res );
	int num8 = this->Index( normZ - num2, res );
	int num9 = this->Index( normZ + num2, res );
	for ( int i = num8; i <= num9; i++ ) {
		int num10 = i - num5;
		int num11 = num10 * num10;
		for ( int j = num6; j <= num7; j++ ) {
			int num12 = j - num4;
			if ( ( float )( num12 * num12 + num11 ) <= num3 ) {
				num |= topologyMap[ i * res + j ];
			}
		}
	}
	return num;
}

std::pair<Vector3, float> TerrainTexturing::GetCoarseVectorToShore( Vector2 uv, int shoreMapSize, Vector4* shoreVectors, float shoreDistanceScale ) {
	int num = shoreMapSize;
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
	Vector4 xyz = shoreVectors[ num11 ];
	Vector4 xyz2 = shoreVectors[ num12 ];
	Vector4 xyz3 = shoreVectors[ num13 ];
	Vector4 xyz4 = shoreVectors[ num14 ];
	Vector3 vector;
	vector.x = ( xyz2.x - xyz.x ) * num7 + xyz.x;
	vector.y = ( xyz2.y - xyz.y ) * num7 + xyz.y;
	vector.z = ( xyz2.z - xyz.z ) * num7 + xyz.z;
	Vector3 vector2;
	vector2.x = ( xyz4.x - xyz3.x ) * num7 + xyz3.x;
	vector2.y = ( xyz4.y - xyz3.y ) * num7 + xyz3.y;
	vector2.z = ( xyz4.z - xyz3.z ) * num7 + xyz3.z;
	float num15 = ( vector2.x - vector.x ) * num8 + vector.x;
	float num16 = ( vector2.y - vector.y ) * num8 + vector.y;
	float num17 = ( vector2.z - vector.z ) * num8 + vector.z;
	return { Vector3( num15, 0.f, num16 ), num17 * shoreDistanceScale };
}