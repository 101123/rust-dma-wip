#pragma once

#include <math.h>

#define _pow2( x ) x * x

inline float lerp( float from, float to, float t ) {
    return to * t + from * ( 1.f - t );
}
