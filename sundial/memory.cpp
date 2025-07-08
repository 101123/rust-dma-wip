#include "memory.h"

#include <windows.h>

bool compare_pattern( uint8_t* base, uint8_t* pattern, size_t mask ) {
	for ( ; mask; ++base, ++pattern, mask-- ) {
		if ( *pattern != 0xCC && *base != *pattern ) {
			return false;
		}
	}

	return true;
}

uintptr_t find_pattern( uint8_t* base, size_t size, uint8_t* pattern, size_t mask ) {
	size -= mask;

	for ( size_t i = 0; i <= size; i++ ) {
		uint8_t* address = &base[ i ];

		if ( compare_pattern( address, pattern, mask ) ) {
			return ( uintptr_t )address;
		}
	}

	return 0;
}

uintptr_t find_pattern_image( uintptr_t image, const char* pattern ) {
	IMAGE_DOS_HEADER dos_header = *( IMAGE_DOS_HEADER* )( image );
	IMAGE_NT_HEADERS nt_headers = *( IMAGE_NT_HEADERS* )( image + dos_header.e_lfanew );

	uintptr_t section_base = image + dos_header.e_lfanew + FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +
		nt_headers.FileHeader.SizeOfOptionalHeader;

	for ( int i = 0; i < nt_headers.FileHeader.NumberOfSections; i++ ) {
		IMAGE_SECTION_HEADER section =
			*( IMAGE_SECTION_HEADER* )( section_base + ( i * sizeof( IMAGE_SECTION_HEADER ) ) );

		if ( ( section.Characteristics & IMAGE_SCN_MEM_EXECUTE ) == 0 ||
			( section.Characteristics & IMAGE_SCN_MEM_DISCARDABLE ) != 0 ) {
			continue;
		}

		uintptr_t result = find_pattern( ( uint8_t* )image + section.VirtualAddress,
			max( section.SizeOfRawData, section.Misc.VirtualSize ), ( uint8_t* )pattern, strlen( pattern ) );

		if ( result ) {
			return result;
		}
	}

	return 0;
}

uintptr_t find_pattern_remote( uintptr_t address, size_t size, const char* pattern, size_t mask ) {
	uint8_t buffer[ PAGE_SIZE + MAX_PATTERN_SIZE ];
	memset( buffer, 0xCC, mask );

	for ( int i = 0; i < ( size / PAGE_SIZE ); i++ ) {
		uintptr_t va = address + ( i * PAGE_SIZE );
		read_memory( va, &buffer[ mask ], PAGE_SIZE );

		uintptr_t result = find_pattern( buffer, PAGE_SIZE + mask, ( uint8_t* )pattern, mask );

		if ( result ) {
			return va + ( result - ( uintptr_t )&buffer[ mask ] );
		}

		memcpy( buffer, &buffer[ PAGE_SIZE ], mask );
	}
}

uintptr_t find_pattern_image_remote( uintptr_t image, const char* pattern ) {
	IMAGE_DOS_HEADER dos_header = read_memory<IMAGE_DOS_HEADER>( image );
	IMAGE_NT_HEADERS nt_headers = read_memory<IMAGE_NT_HEADERS>( image + dos_header.e_lfanew );

	uintptr_t section_base = image + dos_header.e_lfanew + FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +
		nt_headers.FileHeader.SizeOfOptionalHeader;

	for ( int i = 0; i < nt_headers.FileHeader.NumberOfSections; i++ ) {
		IMAGE_SECTION_HEADER section =
			read_memory<IMAGE_SECTION_HEADER>( section_base + ( i * sizeof( IMAGE_SECTION_HEADER ) ) );

		if ( ( section.Characteristics & IMAGE_SCN_MEM_EXECUTE ) == 0 ||
			( section.Characteristics & IMAGE_SCN_MEM_DISCARDABLE ) != 0 ) {
			continue;
		}

		uintptr_t result = find_pattern_remote( image + section.VirtualAddress,
			max( section.SizeOfRawData, section.Misc.VirtualSize ), pattern, strlen( pattern ) );

		if ( result ) {
			return result;
		}
	}

	return 0;
}

uintptr_t relative_32( uintptr_t instruction, int offset ) {
	int relative = read_memory<int>( instruction + offset );
	return instruction + relative + offset + sizeof( int );
}