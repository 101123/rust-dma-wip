#include "dma.h"

#include <memprocfs/vmmdll.h>

uint32_t dma_manager::get_process_id( const char* process_name ) {
    VMMDLL_PROCESS_INFORMATION* process_information = nullptr;
    DWORD count = 0;
    if ( !VMMDLL_ProcessGetInformationAll( ( VMM_HANDLE )m_vmm_handle, &process_information, &count ) )
        return 0;

    uint32_t process_id = 0;

    for ( size_t i = 0; i < count; i++ ) {
        if ( strcmp( process_information[ i ].szNameLong, process_name ) == 0 ) {
            process_id = process_information[ i ].dwPID;
            break;
        }
    }

    VMMDLL_MemFree( process_information );
    return process_id;
}

void dma_manager::set_process_id( uint32_t process_id ) {
    m_pid = process_id;
}

uintptr_t dma_manager::get_module_base_address( const char* name ) {
    return VMMDLL_ProcessGetModuleBaseU( ( VMM_HANDLE )m_vmm_handle, m_pid, name );
}

bool dma_manager::read_memory( uintptr_t address, void* buffer, size_t size ) {
    DWORD read = 0;
    BOOL result = VMMDLL_MemReadEx( ( VMM_HANDLE )m_vmm_handle, m_pid, address, ( PBYTE )buffer, size, NULL, VMMDLL_FLAG_NOCACHE );
    return result && read == size;
}

bool dma_manager::write_memory( uintptr_t address, void* buffer, size_t size ) {
    return VMMDLL_MemWrite( ( VMM_HANDLE )m_vmm_handle, m_pid, address, ( PBYTE )buffer, size );
}

void* dma_manager::initialize_scatter_request() {
    return VMMDLL_Scatter_Initialize( ( VMM_HANDLE )m_vmm_handle, m_pid, VMMDLL_FLAG_NOCACHE );
}

void dma_manager::free_scatter_request( void* scatter_handle ) {
    return VMMDLL_Scatter_CloseHandle( scatter_handle );
}

bool dma_manager::clear_scatter_request( void* scatter_handle ) {
    return VMMDLL_Scatter_Clear( scatter_handle, m_pid, VMMDLL_FLAG_NOCACHE );
}

bool dma_manager::add_scatter_read( void* scatter_handle, uintptr_t address, void* buffer, size_t size ) {
    return VMMDLL_Scatter_PrepareEx( scatter_handle, address, size, ( PBYTE )buffer, NULL );
}

bool dma_manager::add_scatter_write( void* scatter_handle, uintptr_t address, void* buffer, size_t size ) {
    return VMMDLL_Scatter_PrepareWriteEx( scatter_handle, address, ( PBYTE )buffer, size );
}

bool dma_manager::execute_scatter_request( void* scatter_handle ) {
    return VMMDLL_Scatter_Execute( scatter_handle );
}

bool dma_manager::initialize() {
    LPCSTR args[] = { "" , "-device", "fpga://algo=0" };
    m_vmm_handle = VMMDLL_Initialize( _countof( args ), args );
    return m_vmm_handle != nullptr;
}