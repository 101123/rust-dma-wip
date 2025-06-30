#pragma once

#include "dma.h"

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

#include "field.h"

class scatter_request {
public:
    scatter_request() {
        m_handle = dma.initialize_scatter_request();
        m_dirty = false;
    }

    ~scatter_request() {
        if ( initialized() ) {
            dma.free_scatter_request( m_handle );
        }

        m_handle = nullptr;
    }

    scatter_request( const scatter_request& ) = delete;
    scatter_request& operator=( const scatter_request& ) = delete;

    bool initialized() {
        return m_handle != nullptr;
    }

    bool clear() {
        m_dirty = false;

        return dma.clear_scatter_request( m_handle );
    }

    template <typename T, typename A>
    bool add_read( T address, A* buffer ) {
        m_dirty = true;
        static_assert( sizeof( A ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        return dma.add_scatter_read( m_handle, (uintptr_t)address, buffer, sizeof( buffer ) );
    }

    template <typename Type, size_t Offset>
    bool add_read( Field<Type, Offset>* field, Type* result ) {
        return add_read( field->address_of(), result );
    }

    template <typename T, typename A>
    bool add_write( T address, A* buffer ) {
        m_dirty = true;
        static_assert( sizeof( A ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        return dma.add_scatter_write( m_handle, ( uintptr_t )address, buffer, sizeof( buffer ) );
    }

    bool execute() {
        return dma.execute_scatter_request( m_handle );
    }

    bool dirty() {
        return m_dirty;
    }

private:
    void* m_handle;
    bool m_dirty;
};

uintptr_t find_pattern_image( uintptr_t image, const char* pattern );
uintptr_t find_pattern_image_remote( uintptr_t image, const char* pattern );
uintptr_t relative_32( uintptr_t instruction, int offset );