#include "renderer.h"
#include "render.h"
#include "assets.h"
#include "dma.h"
#include "global.h"

#include <memprocfs/leechcore.h>

int main() {
    if ( !dma.initialize() ) {
        LOG( "failed to initialize dma!\n" );
        return 1;
    }

    if ( !renderer.initialize() ) {
        LOG( "failed to initialize renderer!\n" );
        return 2;
    }

    uint32_t process_id = dma.get_process_id( "RustClient.exe" );
    if ( !process_id ) {
        LOG( "failed to find rust process!\n" );
        return 3;
    }

    dma.set_process_id( process_id );

    game_assembly = dma.get_module_base_address( "GameAssembly.dll" );
    if ( !game_assembly ) 
        return 4;

    unity_player = dma.get_module_base_address( "UnityPlayer.dll" );
    if ( !unity_player )
        return 5;
    
    CreateThread( NULL, 0, ( LPTHREAD_START_ROUTINE )render_thread, NULL, 0, NULL );

    while ( true ) {
        Sleep( 1000 );
    }

    return 0;
}