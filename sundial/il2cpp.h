#pragma once

#include "scatter.h"
#include "offsets.h"
#include "global.h"

enum handle_type {
	handle_weak,
	handle_weak_track,
	handle_normal,
	handle_pinned,
	handle_max
};

struct handle_data {
	uintptr_t bitmap;
	uintptr_t entries;
	uint32_t size;
	uint8_t type;
	uint32_t slot_hint : 24;
	uintptr_t domain_ids;
};

template <typename T>
inline bool il2cpp_gchandle_get_target( uint32_t gchandle, T* result ) {
	uint32_t slot = gchandle >> 3;
	uint32_t type = ( gchandle & 7 ) - 1;
	if ( type > 3 )
		return false;

	handle_data handles = read_memory<handle_data>(
		game_assembly + Offsets::GameAssembly::gc_handles + ( sizeof( handle_data ) * type ) );

	if ( slot < handles.size ) {
		uint32_t slot_bits = read_memory<uint32_t>( handles.bitmap + ( sizeof( uint32_t ) * ( slot / 32 ) ) );

		if ( slot_bits & ( 1 << ( slot % 32 ) ) ) {
			if ( handles.type > 1 ) {
				*result = read_memory<T>( handles.entries + ( sizeof( uintptr_t ) * slot ) );
				return *result != 0;
			}
		}
	}

	return false;
}

class get_hidden_values_task {
public:
	bool cache_gc_handles( scatter_request* scatter ) {
		return scatter->add_read( game_assembly + Offsets::GameAssembly::gc_handles, m_gc_handles, sizeof( m_gc_handles ) );
	}

	bool cache_entries( scatter_request* scatter ) {
		bool status = true;

		for ( size_t i = 0; i < _countof( m_gc_handles ); i++ ) {
			const handle_data& handles = m_gc_handles[ i ];
			if ( !handles.entries || ( handles.size <= 0 || handles.size > 1024 ) )
				continue;

			m_entries[ i ].resize( handles.size, {} );

			if ( !scatter->add_read( handles.entries, m_entries[ i ].begin(), handles.size * sizeof( void* ) ) ) {
				status = false;
				break;
			}
		}

		return status;
	}

	template <typename T>
	inline bool get( uint32_t gchandle, T* result ) {
		uint32_t slot = gchandle >> 3;
		uint32_t type = ( gchandle & 7 ) - 1;
		if ( type > 3 )
			return false;

		if ( slot > m_entries[ type ].capacity() )
			return false;

		*result = ( T )m_entries[ type ][ slot ];
		return true;
	}

private:
	handle_data m_gc_handles[ handle_type::handle_max ];
	fast_vector<void*> m_entries[ handle_type::handle_max ];
};