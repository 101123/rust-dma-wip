#include "renderer.h"
#include "render.h"
#include "assets.h"
#include "dma.h"

#include <memprocfs/leechcore.h>

int main() {
    if ( !dma.initialize() ) {
        printf( "failed to initialize dma\n" );
        return 1;
    }

    if ( !renderer.initialize() ) {
        printf( "failed to initialize renderer!\n" );
        return 1;
    }

   /* if ( !assets.load( "D:\\Repositories\\sundial\\x64\\Release\\assets.bin" ) ) {
        printf( "failed to load assets!\n" );
        return 2;
    }*/
    
    CreateThread( NULL, 0, ( LPTHREAD_START_ROUTINE )render_thread, NULL, 0, NULL );

    while ( true ) {
        Sleep( 1000 );
    }

    return 0;
}