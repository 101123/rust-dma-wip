#pragma once

#include <cstdint>

struct process_info {
	uint32_t m_pid;
	uintptr_t m_cr3;
};

class dma_manager {
public:
	bool initialize();

	process_info get_process_info( const char* process_name );
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
	void* m_handle;
	uint32_t m_pid;
};

inline dma_manager dma;