#pragma once

#include "memory.h"
#include "offsets.h"
#include "global.h"

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
	static_assert( sizeof( T ) == sizeof( uintptr_t ), "size of result must be equivalent to size of uintptr_t" );

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
