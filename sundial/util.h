#pragma once

namespace util {
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
}