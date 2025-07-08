#include "dma.h"

#define DMA

#ifdef DMA
#include <memprocfs/vmmdll.h>
#else
#include <windows.h>
#include <tlhelp32.h>
#endif

process_info dma_manager::get_process_info( const char* process_name ) {
#ifdef DMA
    VMMDLL_PROCESS_INFORMATION* process_information = nullptr;
    DWORD count = 0;
    if ( !VMMDLL_ProcessGetInformationAll( ( VMM_HANDLE )m_handle, &process_information, &count ) )
        return process_info();

    process_info process_info = {};

    for ( size_t i = 0; i < count; i++ ) {
        VMMDLL_PROCESS_INFORMATION* entry = &process_information[ i ];
        if ( !entry->paDTB )
            continue;

        if ( strcmp( process_information[ i ].szNameLong, process_name ) == 0 ) {
            process_info = {
                .m_pid = process_information[ i ].dwPID,
                .m_cr3 = process_information[ i ].paDTB
            };

            break;
        }
    }

    VMMDLL_MemFree( process_information );
    return process_info;
#else
    HANDLE snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    if ( snapshot == INVALID_HANDLE_VALUE )
        return 0;

    PROCESSENTRY32 process_entry {
        .dwSize = sizeof( PROCESSENTRY32 )
    };

    uint32_t process_id = 0;

    if ( Process32First( snapshot, &process_entry ) ) {
        do {
            if ( strcmp( process_entry.szExeFile, process_name ) == 0 ) {
                process_id = process_entry.th32ProcessID;
                break;
            }

        } while ( Process32Next( snapshot, &process_entry ) );
    }

    CloseHandle( snapshot );
    return process_id;
#endif
}

void dma_manager::set_process_id( uint32_t process_id ) {
#ifdef DMA
    m_pid = process_id;
#else
    m_handle = ( void* )OpenProcess( PROCESS_ALL_ACCESS, FALSE, process_id );
    m_pid = process_id;
#endif
}

uintptr_t dma_manager::get_module_base_address( const char* name ) {
#ifdef DMA
    return VMMDLL_ProcessGetModuleBaseU( ( VMM_HANDLE )m_handle, m_pid, name );
#else
    HANDLE snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, m_pid );
    if ( snapshot == INVALID_HANDLE_VALUE )
        return 0;

    MODULEENTRY32 module_entry {
        .dwSize = sizeof( MODULEENTRY32 )
    };

    uintptr_t module_base = 0;

    if ( Module32First( snapshot, &module_entry ) ) {
        do {
            if ( strcmp( module_entry.szModule, name ) == 0 ) {
                module_base = ( uintptr_t )module_entry.modBaseAddr;
                break;
            }

        } while ( Module32Next( snapshot, &module_entry ) );
    }

    CloseHandle( snapshot );
    return module_base;
#endif
}

bool dma_manager::read_memory( uintptr_t address, void* buffer, size_t size ) {
#ifdef DMA
    DWORD read = 0;
    BOOL result = VMMDLL_MemReadEx( ( VMM_HANDLE )m_handle, ( DWORD )-1, address, ( PBYTE )buffer, size, &read, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_SCATTER_PREPAREEX_NOMEMZERO );
    return result && read == size;
#else
    return ReadProcessMemory( ( HANDLE )m_handle, ( LPCVOID )address, ( LPVOID )buffer, size, nullptr );
#endif
}

bool dma_manager::write_memory( uintptr_t address, void* buffer, size_t size ) {
#ifdef DMA
    return VMMDLL_MemWrite( ( VMM_HANDLE )m_handle, m_pid, address, ( PBYTE )buffer, size );
#else
    return WriteProcessMemory( ( HANDLE )m_handle, ( LPVOID )address, ( LPCVOID )buffer, size, nullptr );
#endif
}

void* dma_manager::initialize_scatter_request() {
#ifdef DMA
    return VMMDLL_Scatter_Initialize( ( VMM_HANDLE )m_handle, ( DWORD )-1, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_SCATTER_PREPAREEX_NOMEMZERO );
#else

#endif
}

void dma_manager::free_scatter_request( void* scatter_handle ) {
#ifdef DMA
    return VMMDLL_Scatter_CloseHandle( scatter_handle );
#else

#endif
}

bool dma_manager::clear_scatter_request( void* scatter_handle ) {
#ifdef DMA
    return VMMDLL_Scatter_Clear( scatter_handle, ( DWORD )-1, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_SCATTER_PREPAREEX_NOMEMZERO );
#else
    return true;
#endif
}

bool dma_manager::add_scatter_read( void* scatter_handle, uintptr_t address, void* buffer, size_t size ) {
#ifdef DMA
    return VMMDLL_Scatter_PrepareEx( scatter_handle, address, size, ( PBYTE )buffer, NULL );
#else
    return true;
#endif
}

bool dma_manager::add_scatter_write( void* scatter_handle, uintptr_t address, void* buffer, size_t size ) {
#ifdef DMA
    return VMMDLL_Scatter_PrepareWriteEx( scatter_handle, address, ( PBYTE )buffer, size );
#else
    return true;
#endif
}

bool dma_manager::execute_scatter_request( void* scatter_handle ) {
#ifdef DMA
    return VMMDLL_Scatter_Execute( scatter_handle );
#else
    return true;
#endif
}

bool dma_manager::initialize() {
#ifdef DMA
    LPCSTR args[] = { "" , "-device", "fpga://algo=0", "-norefresh" };
    m_handle = VMMDLL_Initialize( _countof( args ), args );
    return m_handle != nullptr;
#else
    return true;
#endif
}