#include "render.h"
#include "renderer.h"
#include "assets.h"
#include "sdk.h"
#include "shared.h"
#include "engine.h"

util::fifo_queue<players*, 32> free_queue;

players* players_msg;

int bone_connections[][ 2 ] = {
    { 1, 0 }, { 0, 3 }, { 3, 2 },
    { 3, 4 }, { 4, 6 }, { 6, 8 },
    { 8, 10 }, { 2, 12 }, { 12, 14 },
    { 14, 16 }, { 3, 5 }, { 5, 7 },
    { 7, 9 }, { 9, 11 }, { 2, 13 },
    { 13, 15 }, { 15, 17 }
};

void render_thread() {
    while ( true ) {
        engine.update( nullptr );

        renderer.begin_frame();

        message* msg = nullptr;
        while ( render_queue.try_pop( msg ) ) {
            if ( msg->m_type == message_type::entities ) {

            }

            else if ( msg->m_type == message_type::players ) {
                if ( players_msg ) {
                    if ( free_queue.count() == free_queue.capacity() ) {
                        // LOG( "freed a niger!\n" );
                        delete free_queue.pop();
                    }

                    free_queue.push( players_msg );
                }

                players_msg = ( players* )msg;
            }
        }

        if ( players_msg ) {
            for ( player player : players_msg->m_players ) {
                vec2 screen[ bone_count ];
                bool success[ bone_count ];
                for ( int i = 0; i < bone_count; i++ ) {
                    success[ i ] = engine.w2s( &player.m_bone_positions[ i ], &screen[ i ] );
                }

                for ( int j = 0; j < bone_count; j++ ) {
                    int a = bone_connections[ j ][ 0 ];
                    int b = bone_connections[ j ][ 1 ];
                    if ( !success[ a ] || !success[ b ] )
                        continue;

                    vec2* a_pos = &screen[ a ];
                    vec2* b_pos = &screen[ b ];
                    renderer.draw_line( a_pos->x, a_pos->y, b_pos->x, b_pos->y, 1.15f, 0xFFFFFFFF );
                }
            }
        }

        renderer.end_frame();
    }
}