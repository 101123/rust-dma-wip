#pragma once

#include <vector>
#include <string>

class stream_reader {
public:
    stream_reader() = delete;
    stream_reader( const std::vector<uint8_t>& buffer ) : m_buffer( buffer ), m_position( 0ull ) {};

    template <typename T>
    T read() {
        T buffer;
        memcpy( &buffer, ( void* )( m_buffer.data() + m_position ), sizeof( T ) );
        m_position += sizeof( T );
        return buffer;
    }

    void* read( size_t size ) {
        void* buffer = ( void* )( m_buffer.data() + m_position );
        m_position += size;
        return buffer;
    }

    std::string read_string() {
        uint16_t size = read<uint16_t>();
        const char* string = ( const char* )read( size );

        return std::string( string );
    }

private:
    const std::vector<uint8_t>& m_buffer;
    size_t m_position;
};