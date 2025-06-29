#pragma once

#include "offsets.h"
#include "offsets_manual.h"
#include "memory.h"

#include <unity/Vector2.h>
#include <unity/Vector3.h>
#include <unity/Vector4.h>

#include <tuple>

#define ixstringify( x ) #x
#define xstringify( x ) ixstringify( x )
#define ixstrcat( x, y ) x##y
#define xstrcat( x, y ) ixstrcat( x, y )
    
#define FIELD( Type, Name, Offset )                                                                     \
    Type xstrcat( _Get, Name )() const {                                                                \
        return read_memory<Type>( reinterpret_cast<uintptr_t>( this ) + Offset );                       \
    }                                                                                                   \
                                                                                                        \
    void xstrcat( _Set, Name )( Type Value ) {                                                          \
        write_memory<Type>( reinterpret_cast<uintptr_t>( this ) + Offset, Value );                      \
    }                                                                                                   \
                                                                                                        \
    __declspec( property( get = xstrcat( _Get, Name ), put = xstrcat( _Set, Name ) ) ) Type Name;

using Vector2 = Vector2f;
using Vector3 = Vector3f;
using Vector4 = Vector4f;

class Il2CppClass;
class TerrainHeightMap;
class TerrainSplatMap;
class TerrainTopologyMap;
class TerrainTexturing;
class TerrainMeta;

template <typename T>
struct NativeArray {
    void* m_Buffer;
    int m_Length;
    int m_AllocatorLabel;

    std::pair<int, T*> get() {
        if ( !m_Buffer || !m_Length )
            return { 0, nullptr };

        T* buffer = new T[ m_Length ];
        read_memory( m_Buffer, buffer, m_Length * sizeof( T ) );

        return { m_Length, buffer };
    }
};

class Il2CppClass {
public:

};






class Camera {
public:

};


class MainCamera {
public:
    class StaticFields {
    public:
        FIELD( Camera*, mainCamera, Offsets::MainCamera::mainCamera );
    };

    inline static StaticFields* static_fields;
};




class World {
public:
    class StaticFields {
    public:
        FIELD( int, _size, Offsets::World_Static::_size );
    };

    inline static StaticFields* static_fields;
};

#define BYTE_TO_FLOAT( b ) ( float )b * 0.003921569f
#define FLOAT_TO_BYTE( f ) ( uint8_t )f * 255.999f;
#define SHORT_TO_FLOAT( s ) ( float )s * 3.051944E-05f;

class Mathf {
public:
    static bool IsPowerOfTwo( int value ) {
        return ( value & ( value - 1 ) ) == 0;
    }

    static int Clamp( int value, int min, int max ) {
        return ( value < min ) ? min : ( value > max ) ? max : value;
    }

    static float Clamp( float value, float min, float max ) {
        return ( value < min ) ? min : ( value > max ) ? max : value;
    }

    static float Clamp01( float value ) {
        return ( value < 0.f ) ? 0.f : ( value > 1.f ) ? 1.f : value;
    }

    static int Min( int a, int b ) {
        return a < b ? a : b;
    }

    static float Max( float a, float b ) {
        return a > b ? a : b;
    }

    static float Lerp( float a, float b, float t ) {
        return a + ( b - a ) * Clamp01( t );
    }
};

template <typename T>
class TerrainMap {
public:
    FIELD( int, res, Offsets::TerrainMap::res );
    FIELD( NativeArray<T>, src, Offsets::TerrainMap::src );

    int Index( float normalized, int res ) {
        int num = ( int )( normalized * ( float )res );
        if ( num < 0 ) {
            return 0;
        }

        else if ( num <= res - 1 ) {
            return num;
        }

        return res - 1;
    }
};

class TerrainHeightMap : public TerrainMap<uint16_t> {
public:
    FIELD( float, normY, Offsets::TerrainHeightMap::normY );

    float GetHeight( float normX, float normZ, Vector3 terrainPosition, Vector3 terrainSize, int res, uint16_t* heightMap );
    float GetHeight01( float normX, float normZ, int res, uint16_t* heightMap );
    float GetHeight01( int x, int z, int res, uint16_t* heightMap );
    Vector3 GetNormal( float normX, float normZ, int res, uint16_t* heightMap, float normY );
    Vector3 GetNormal( int x, int z, int res, uint16_t* heightMap, float normY );
};

class TerrainSplatMap : public TerrainMap<uint8_t> {
public:
    float GetSplat( float normX, float normZ, int mask, int res, uint8_t* splatMap );
    float GetSplat( int x, int z, int mask, int res, uint8_t* splatMap );
};

class TerrainTopologyMap : public TerrainMap<int32_t> {
public:
    int GetTopology( float normX, float normZ, float radius, Vector3 terrainOneOverSize, int res, int32_t* topologyMap );
};

class TerrainTexturing {
public:
    FIELD( float, terrainSize, Offsets::TerrainTexturing::terrainSize );
    FIELD( int, shoreMapSize, Offsets::TerrainTexturing::shoreMapSize );
    FIELD( float, shoreDistanceScale, Offsets::TerrainTexturing::shoreDistanceScale );
    FIELD( NativeArray<Vector4>, shoreVectors, Offsets::TerrainTexturing::shoreVectors );

    std::pair<Vector3, float> GetCoarseVectorToShore( Vector2 uv, int shoreMapSize, Vector4* shoreVectors, float shoreDistanceScale );
};

class TerrainMeta {
public:
    class StaticFields {
    public:
        FIELD( Vector3, Position, Offsets::TerrainMeta::Position );
        FIELD( Vector3, Size, Offsets::TerrainMeta::Size );
        FIELD( Vector3, OneOverSize, Offsets::TerrainMeta::OneOverSize );
        FIELD( TerrainHeightMap*, HeightMap, Offsets::TerrainMeta::HeightMap );
        FIELD( TerrainSplatMap*, SplatMap, Offsets::TerrainMeta::SplatMap );
        FIELD( TerrainTopologyMap*, TopologyMap, Offsets::TerrainMeta::TopologyMap );
        FIELD( TerrainTexturing*, Texturing, Offsets::TerrainMeta::Texturing );
    };

    static inline StaticFields* static_fields;
};
