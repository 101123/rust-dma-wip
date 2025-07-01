#pragma once

#include "dma.h"

#include <array>
#include <tuple>

template <typename A>
inline bool read_memory( A address, void* buffer, size_t size ) {
    static_assert( sizeof( A ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

    return dma.read_memory( ( uintptr_t )address, buffer, size );
}

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

template <size_t N>
constexpr inline size_t _minimum( const std::array<size_t, N>& values ) {
    size_t minimum = values[ 0 ];
    for ( size_t i = 1; i < N; ++i ) {
        if ( values[ i ] < minimum ) {
            minimum = values[ i ];
        }
    }

    return minimum;
}

template <size_t N>
constexpr inline size_t _maximum( const std::array<size_t, N>& values ) {
    size_t maximum = values[ 0 ];
    for ( size_t i = 1; i < N; ++i ) {
        if ( values[ i ] > maximum ) {
            maximum = values[ i ];
        }
    }

    return maximum;
}

template <typename... Types, typename T, size_t N = sizeof...( Types )>
inline std::tuple<Types...> read_memory( T address, const std::array<size_t, N>& offsets, uint8_t* alloc = nullptr ) {
    static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

    size_t minimum = _minimum( offsets );
    size_t maximum = _maximum( offsets );
    size_t addon = 0;
    size_t index = 0;
    ( ..., (
        offsets[ index ] == maximum ? addon = sizeof( Types ) : 0,
        index++
        ) );
    size_t size = maximum - minimum + addon;
    uint8_t* buffer = alloc ? alloc : ( uint8_t* )malloc( size );
    if ( !buffer )
        return {};
    read_memory( ( uintptr_t )address + minimum, buffer, size );
    index = 0;
    std::tuple<Types...> result = { *( Types* )( buffer + offsets[ index++ ] - minimum )... };
    if ( !alloc )
        free( buffer );
    return result;
}

uintptr_t find_pattern_image( uintptr_t image, const char* pattern );
uintptr_t find_pattern_image_remote( uintptr_t image, const char* pattern );
uintptr_t relative_32( uintptr_t instruction, int offset );