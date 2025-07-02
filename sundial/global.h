#pragma once

#include "util.h"

#include <imgui/imgui.h>

#include <cstdio>

template<typename T>
using fast_vector = ImVector<T>;

#ifndef DEBUG
#define LOG( msg, ... ) printf( msg, __VA_ARGS__ );
#endif

inline uintptr_t game_assembly;
inline uintptr_t unity_player;
