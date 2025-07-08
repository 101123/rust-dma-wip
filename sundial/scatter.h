#pragma once

#include "memory.h"
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

    template <typename A>
    inline bool add_physical_read( A address, void* buffer, size_t size ) {
        static_assert( sizeof( A ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        uintptr_t va = ( uintptr_t )address;
        uintptr_t dest = ( uintptr_t )buffer;
        size_t remaining = size;

        while ( remaining ) {
            size_t offset_in_page = va & ( PAGE_SIZE - 1 );
            size_t bytes_in_page = PAGE_SIZE - offset_in_page;
            size_t read_size = bytes_in_page < remaining ? bytes_in_page : remaining; // min

            uintptr_t pa = 0;
            if ( !tlb.translate( va, &pa ) )
                return false;

            if ( !dma.add_scatter_read( m_handle, pa, ( void* )dest, read_size ) )
                return false;

            va += read_size;
            dest += read_size;
            remaining -= read_size;
        }

        return true;
    }

    template <typename T, typename A>
    bool add_read( T address, A* buffer, size_t size ) {
        static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        m_dirty = true;

        return add_physical_read( address, buffer, size );
    }

    template <typename T, typename A>
    bool add_read( T address, A* buffer ) {
        static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        m_dirty = true;

        return add_read( address, buffer, sizeof( A ) );
    }

    template <typename Type, size_t Offset, void( *Decrypt )( uint32_t* ) = nullptr, void( *Encrypt )( uint32_t* ) = nullptr>
    bool add_field( Field<Type, Offset, Decrypt, Encrypt>* field, Type* result ) {
        return add_read( field->address_of(), result );
    }

    template <typename T, typename A>
    bool add_write( T address, A* buffer ) {
        static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of address must be equivalent to size of uintptr_t" );

        m_dirty = true;

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
    void* m_handle;
    bool m_dirty;
};