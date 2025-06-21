#pragma once

#include <cstdint>

class dma_manager {
public:
	bool initialize();

	uint32_t get_process_id( const char* process_name );
	void set_process_id( uint32_t process_id );

	uintptr_t get_module_base_address( const char* name );

	bool read_memory( uintptr_t address, void* buffer, size_t size );
	bool write_memory( uintptr_t address, void* buffer, size_t size );

	void* initialize_scatter_request();
	void free_scatter_request( void* scatter_handle );
	bool clear_scatter_request( void* scatter_handle );
	bool add_scatter_read( void* scatter_handle, uintptr_t address, void* buffer, size_t size );
	bool add_scatter_write( void* scatter_handle, uintptr_t address, void* buffer, size_t size );
	bool execute_scatter_request( void* scatter_handle );

private:
	void* m_vmm_handle;
	uint32_t m_pid;
};

inline dma_manager dma;