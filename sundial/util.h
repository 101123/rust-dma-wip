#pragma once

#include <cstdint>
#include <intrin.h>

enum time_unit {
	microseconds = 10,
	milliseconds = 10000,
	seconds = 10000000
};

namespace util {
	class mutex {
	public:
		mutex( char* lock ) : m_lock( lock ) {
			while ( true ) {
				if ( *m_lock == 0 && _InterlockedExchange8( ( char* )m_lock, 1 ) == 0 ) {
					break;
				}

				_mm_pause();
			}
		}

		~mutex() {
			*m_lock = false;
		}

	private:
		char* m_lock;
	};

	template <uint64_t unit>
	class timer {
	public:
		timer() : m_previous_time( get_time() ) {}

		bool has_elapsed( uint64_t time ) {
			if ( ( ( get_time() - m_previous_time ) / unit ) > time ) {
				m_previous_time = get_time();
				return true;
			}

			return false;
		}

		uint64_t get_elapsed() {
			return ( get_time() - m_previous_time ) / unit;
		}

		double get_delta_time() {
			uint64_t time = get_time();
			uint64_t delta = time - m_previous_time;
			m_previous_time = time;
			return ( double )delta / unit;
		}

	private:
		uint64_t get_time() {
			return ( *( uint64_t* )( 0x7FFE0018ull ) << 32 ) | *( uint32_t* )( 0x7FFE0014ull );
		}

		uint64_t m_previous_time;
	};

	template <typename T, size_t N>
	class tls {
	public:
		T* get() {
			for ( int i = 0; i < N; i++ ) {
				if ( m_thread_ids[ i ] == get_thread_id() ) {
					return &m_buffer[ i ];
				}
			}

			mutex mutex( &m_lock );

			for ( int j = 0; j < N; j++ ) {
				if ( m_thread_ids[ j ] == 0 ) {
					m_thread_ids[ j ] = get_thread_id();
					memset( &m_buffer[ j ], 0, sizeof( T ) );
					return &m_buffer[ j ];
				}
			}

			return nullptr;
		}

	private:
		uint32_t get_thread_id() {
			return *( uint32_t* )( __readgsqword( 0x30 ) + 0x48 );
		}

		T m_buffer[ N ];
		uint32_t m_thread_ids[ N ];
		char m_lock;
	};

	template <typename T, size_t N>
	class fifo_queue {
	public:
		fifo_queue() : m_count( 0 ) {};

		bool push( T item ) {
			if ( m_count < N ) {
				m_buffer[ m_count++ ] = item;
				return true;
			}

			return false;
		}

		T pop() {
			if ( m_count > 0 ) {
				T value = m_buffer[ 0 ];
				memmove( &m_buffer[ 0 ], &m_buffer[ 1 ], sizeof( T ) * ( m_count - 1 ) );
				--m_count;
				return value;
			}

			return T();
		}

		size_t count() {
			return m_count;
		}

		size_t capacity() {
			return N;
		}

	private:
		T m_buffer[ N ];
		size_t m_count;
	};

	inline constexpr uint64_t hash( const char* str ) {
		uint64_t hash = 0xCBF29CE484222325ull;

		while ( *str ) {
			hash = ( hash ^ uint32_t( ( *str >= 'A' && *str <= 'Z' ) ? *str - ( 'A' - 'a' ) : *str ) ) *
				0x100000001B3ull;
			str++;
		}

		return hash;
	}

	inline consteval uint64_t hash_const( const char* str ) {
		return hash( str );
	}

	inline constexpr uint64_t hash_w( const wchar_t* str ) {
		uint64_t hash = 0xCBF29CE484222325ull;

		while ( *str ) {
			hash = ( hash ^ uint32_t( ( *str >= L'A' && *str <= L'Z' ) ? *str - ( L'A' - L'a' ) : *str ) & 0xFF ) *
				0x100000001B3ull;
			str++;
		}

		return hash;
	}

	inline consteval uint64_t hash_w_const( const wchar_t* str ) {
		return hash_w_const( str );
	}
}

#define H( x ) util::hash_const( x )
#define HW( x ) util::hash_w_const( x )