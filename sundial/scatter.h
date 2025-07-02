#pragma once

#include "memory.h"
#include "field.h"

#include <vector>

struct nigga {
    void* a;
    void* b;
    size_t c;
};

class scatter_request {
public:
    scatter_request() {
        m_handle = dma.initialize_scatter_request();
        m_dirty = false;
    }

    ~scatter_request() {
        LOG( "Dtor!\n" );

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
         //m_nigga.clear();

        return dma.clear_scatter_request( m_handle );
    }

    template <typename T, typename A>
    bool add_read( T address, A* buffer, size_t size ) {
        m_dirty = true;

        static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

       /* nigga nig;
        nig.a = ( void* )address;
        nig.b = ( void* )buffer;
        nig.c = size;
        m_nigga.push_back( nig );*/

        return dma.add_scatter_read( m_handle, ( uintptr_t )address, buffer, size );
    }

    template <typename T, typename A>
    bool add_read( T address, A* buffer ) {
        m_dirty = true;
        static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        return add_read( ( uintptr_t )address, buffer, sizeof( A ) );
    }

    template <typename Type, size_t Offset>
    bool add_field( Field<Type, Offset>* field, Type* result ) {
        return add_read( field->address_of(), result );
    }

    template <typename T, typename A>
    bool add_write( T address, A* buffer ) {
        m_dirty = true;
        static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        return dma.add_scatter_write( m_handle, ( uintptr_t )address, buffer, sizeof( A ) );
    }

    bool execute() {
        return dma.execute_scatter_request( m_handle );
    }

    bool execute_and_clear() {
        return execute() && clear();
    }

    bool dirty() {
        return m_dirty;
    }

private:
    // std::vector<nigga> m_nigga;
    void* m_handle;
    bool m_dirty;
};