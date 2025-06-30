#pragma once

#include <cstdint>

template <typename Type, size_t Offset, void( *Decrypt )( uint32_t* ) = nullptr, void( *Encrypt )( uint32_t* ) = nullptr>
class Field {
public:
    uintptr_t address_of() {
        return reinterpret_cast< uintptr_t >( this ) + Offset;
    }

    Type get() {
        Type value = read_memory<Type>( address_of() );

        if ( Decrypt != nullptr ) {
            Decrypt( reinterpret_cast< uint32_t* >( &value ) );
        }

        return value;
    }

    void set( Type value ) {
        if ( Encrypt != nullptr ) {
            Encrypt( reinterpret_cast< uint32_t* >( &value ) );
        }

        write_memory<Type>( address_of(), value );
    }

    operator Type() {
        return get();
    }

    void operator=( Type value ) {
        set( value );
    }

    __declspec( property( get = get ) ) Type value;
};

#define FIELD( Type, Name, Offset ) [[msvc::no_unique_address]] Field<Type, Offset> Name

#define ENCRYPTED_VALUE( Type, Name, Offset, Decrypt, Encrypt ) \
    static void _Decrypt##Name( uint32_t* values ) { for ( size_t i = 0; i < ( sizeof( Type ) / sizeof( uint32_t ) ); i++ ) { Decrypt } }; \
    static void _Encrypt##Name( uint32_t* values ) { for ( size_t i = 0; i < ( sizeof( Type ) / sizeof( uint32_t ) ); i++ ) { Encrypt } }; \
    [[msvc::no_unique_address]] Field<Type, Offset, _Decrypt##Name, _Encrypt##Name> Name