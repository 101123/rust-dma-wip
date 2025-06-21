#pragma once

#include <cstdio>

#ifndef DEBUG
#define LOG( msg, ... ) printf( msg, __VA_ARGS__ );
#endif

inline uintptr_t game_assembly;
inline uintptr_t unity_player;
