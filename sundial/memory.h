#pragma once

#include "dma.h"

template <typename T>
inline void write_memory( uintptr_t address, T value ) {
    dma.write_memory( address, &value, sizeof( value ) );
}

template <typename T, typename A>
inline T read_memory( A address ) {
    static_assert( sizeof( A ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

    T buffer = {};
    dma.read_memory( ( uintptr_t )address, &buffer, sizeof( buffer ) );
    return buffer;
}

uintptr_t find_pattern_image( uintptr_t image, const char* pattern );
uintptr_t find_pattern_image_remote( uintptr_t image, const char* pattern );
uintptr_t relative_32( uintptr_t instruction, int offset );