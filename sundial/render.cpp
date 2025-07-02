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

struct bounds {
    float left, right, top, bottom;
};

bool get_bounds( bounds* bounds, vec2* screen, bool* success, int count, float distance ) {
    *bounds = {
        .left = FLT_MAX,
        .right = FLT_MIN,
        .top = FLT_MAX,
        .bottom = FLT_MIN
    };

    for ( int i = 0; i < count; i++ ) {
        if ( !success[ i ] )
            continue;

        const vec2& pos = screen[ i ];
        if ( pos.x < bounds->left )
            bounds->left = pos.x;
        if ( pos.x > bounds->right )
            bounds->right = pos.x;
        if ( pos.y < bounds->top )
            bounds->top = pos.y;
        if ( pos.y > bounds->bottom )
            bounds->bottom = pos.y;
    }

    if ( bounds->left == FLT_MAX )
        return false;
    if ( bounds->right == FLT_MIN )
        return false;
    if ( bounds->top == FLT_MAX )
        return false;
    if ( bounds->bottom == FLT_MIN )
        return false;

    float padding = ( 1.f / distance ) * 75.f;

    bounds->left -= std::max( padding, 2.f );
    bounds->left = floorf( bounds->left );

    bounds->right += std::max( padding, 4.f );
    bounds->right = floorf( bounds->right );

    bounds->top -= std::max( padding, 2.f );
    bounds->top = floorf( bounds->top );

    bounds->bottom += std::max( padding, 4.f );
    bounds->bottom = floorf( bounds->bottom );

    if ( bounds->top < 0.f && ( bounds->bottom <= std::max( padding, 4.f ) || 
        bounds->bottom > 1440.f ) )
        return false;
    if ( bounds->left < 0.f && bounds->right <= std::max( padding, 4.f ) )
        return false;

    return true;
}

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

                bounds bounds;
                if ( !get_bounds( &bounds, screen, success, bone_count, 100.f ) ) {
                    continue;
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

                renderer.draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 3.f, 0x44000000 );
                renderer.draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 1.f, 0xFFFFFFFF );

                float half = ( bounds.right - bounds.left ) / 2.f;


                renderer.draw_string_a( bounds.left + half, bounds.top - 14.f, fonts::verdana, 12.f, text_flags::centered | text_flags::drop_shadow, 0xFFFFFFFF, "Scientist" );

            }
        }

        renderer.end_frame();
    }
}