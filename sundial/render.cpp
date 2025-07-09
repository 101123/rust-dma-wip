#include "render.h"
#include "renderer.h"
#include "assets.h"
#include "sdk.h"
#include "shared.h"
#include "engine.h"
#include "config.h"

util::fifo_queue<players*, 32> free_queue;

players* players_msg;

cached_player* target_player = nullptr;
float target_distance;

vec2 screen_center;

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

struct VisualWeaponInfo {
    int itemid;
    char letter;
    const char* shortname;
};

VisualWeaponInfo VisualWeapons[] = {
    { -206957888, 104, ( "M2" ) },
    { 1545779598, 112, ( "AK" ) },
    { -1335497659, 112, ( "AK" ) },
    { -139037392, 112, ( "AK" ) },
    { -1812555177, 106, ( "LR" ) },
    { 1588298435, 111, ( "Bolt" ) },
    { 28201841, 105, ( "M39" ) },
    { -778367295, 107, ( "L96" )},
    { -904863145, 98, ( "AR" )},
    { 1796682209, 109, ( "Cutom" )},
    { 1318558775, 103, ( "MP5" )},
    { -1758372725, 97, ( "Thompon" )},
    { -765183617, 114, ( "DB" ) },
    { -41440462, -1, ( "pa" ) },
    { 795371088, 102, ( "Pump" ) },
    { -1367281941, 113, ( "Waterpipe" ) },
    { -75944661, 108, ( "Eoka" ) },
    { 649912614, 100, ( "Revolver" ) },
    { -852563019, -1, ( "M92" ) },
    { 818877484, 99, ( "AP" )},
    { 1373971859, 101, ( "Python" ) },
    { 1953903201, -1, ( "Nailgun" ) },
    { 1965232394, 110, ( "Crobow" )},
    { 1443579727, 116, ( "Bow" )},
    { 884424049, -1, ( "Compound Bow" ) }
};

void draw_players( fast_vector<cached_player>& players ) {
    for ( cached_player& player : players ) {
        if ( player.m_destroyed )
            continue;

        if ( player.m_lifestate != lifestate::alive )
            continue;

        player_visuals* visuals = player.m_klass == base_player::s_klass ? &cvar_players : &cvar_scientists;

        bool wounded = player.m_player_flags & player_flags::wounded;
        if ( wounded && !cvar_wounded.m_enabled )
            continue;

        bool sleeping = player.m_player_flags & player_flags::sleeping;
        if ( sleeping && !cvar_sleeper.m_enabled )
            continue;

        float maximum_distance = visuals->m_maximum_distance;
        if ( player.m_klass == base_player::s_klass ) {
            if ( wounded ) {
                maximum_distance = cvar_wounded.m_maximum_distance;
            }

            else if ( sleeping ) {
                maximum_distance = cvar_sleeper.m_maximum_distance;
            }
        }

        float camera_distance = distance( engine.m_camera_position, player.m_bone_positions[ bone_count - 1 ] );
        if ( camera_distance > maximum_distance )
            continue;

        vec2 screen[ bone_count ];
        bool success[ bone_count ];
        for ( int i = 0; i < bone_count; i++ ) {
            success[ i ] = engine.w2s( &player.m_bone_positions[ i ], &screen[ i ] );
        }

        bounds bounds;
        if ( !get_bounds( &bounds, screen, success, bone_count, camera_distance ) ) {
            continue;
        }

        float screen_distance = distance( screen_center, screen[ 1 ] );
        if ( screen_distance < target_distance ) {
            target_distance = screen_distance;
            target_player = &player;
        }

        float half = ( bounds.right - bounds.left ) / 2.f;

        if ( visuals->m_box ) {
            uint32_t color = visuals->m_box_color;

            renderer.draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 3.f, col32( 0, 0, 0, 48 ) );
            renderer.draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 1.f, color );
        }

        if ( visuals->m_skeleton ) {
            uint32_t color = visuals->m_skeleton_color;

            for ( int j = 0; j < _countof( bone_connections ); j++ ) {
                int a_idx = bone_connections[ j ][ 0 ];
                int b_idx = bone_connections[ j ][ 1 ];
                if ( !success[ a_idx ] || !success[ b_idx ] )
                    continue;

                vec2* a_pos = &screen[ a_idx ];
                vec2* b_pos = &screen[ b_idx ];
                renderer.draw_line( a_pos->x, a_pos->y, b_pos->x, b_pos->y, 1.15f, color );
            }
        }

        if ( visuals->m_name ) {
            uint32_t color = visuals->m_name_color;

            renderer.draw_string_w( bounds.left + half, bounds.top - 14.f,
                fonts::verdana, 12.f, text_flags::centered | text_flags::drop_shadow, color, player.m_name.str );
        }

        localized_item* held_item = nullptr;
        for ( int i = 0; i < 6; i++ ) {
            if ( player.m_belt_items[ i ].m_active ) {
                held_item = player.m_belt_items[ i ].m_localized_item;
            }
        }

        if ( held_item ) {
            for ( auto& wep : VisualWeapons ) {
                if ( wep.itemid == held_item->m_item_id ) {

                    char buf[ 2 ] = {};
                    buf[ 0 ] = wep.letter;

                    renderer.draw_string_a( bounds.left + half, bounds.bottom - 8.f,
                        fonts::icon, 30.f, text_flags::centered | text_flags::drop_shadow, visuals->m_name_color, buf );

                    break;
                }
            }
        }
    }
}

bool menu_open = false;

bool color_picker( const char* label, uint32_t* color ) {
    float color_as_float[ 4 ];
    color_as_float[ 0 ] = ( float )( ( *color >> 0 ) & 0xFF ) / 255.f;
    color_as_float[ 1 ] = ( float )( ( *color >> 8 ) & 0xFF ) / 255.f;
    color_as_float[ 2 ] = ( float )( ( *color >> 16 ) & 0xFF ) / 255.f;
    color_as_float[ 3 ] = ( float )( ( *color >> 24 ) & 0xFF ) / 255.f;

    bool result = ImGui::ColorEdit4( label, color_as_float, ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs |
        ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoTooltip );

    *color = ( ( uint32_t )( color_as_float[ 0 ] * 255.f ) ) |
        ( ( uint32_t )( color_as_float[ 1 ] * 255.f ) << 8 ) |
        ( ( uint32_t )( color_as_float[ 2 ] * 255.f ) << 16 ) |
        ( ( uint32_t )( color_as_float[ 3 ] * 255.f ) << 24 );

    return result;
}

void combo( const char* name, int* value, std::initializer_list<const char*> options ) {
    if ( ImGui::BeginCombo( name, options.begin()[ *value ] ) ) {
        for ( int i = 0; i < options.size(); i++ ) {
            bool selected = false;
            if ( ImGui::Selectable( options.begin()[ i ], &selected ) ) {
                *value = i;
            }
        }

        ImGui::EndCombo();
    }
}

void render_thread() {
    screen_center = vec2(
        0.f + ( ( float )renderer.m_screen_size.x / 2.f ),
        0.f + ( ( float )renderer.m_screen_size.y / 2.f )
    );

    while ( true ) {
        renderer.begin_frame( menu_open );

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

        if ( GetAsyncKeyState( VK_END ) & 0x1 ) {
            menu_open = !menu_open;
        }

        if ( menu_open ) {
            ImGui::Begin( "Cheat" );

            if ( ImGui::BeginTabBar( "VisualsTabBar" ) ) {
                if ( ImGui::BeginTabItem( "Players" ) ) {
                    ImGui::Checkbox( "Enabled", &cvar_players.m_enabled );
                    ImGui::Checkbox( "Box", &cvar_players.m_box ); ImGui::SameLine();
                    color_picker( "Box Color", &cvar_players.m_box_color );
                    ImGui::Checkbox( "Skeleton", &cvar_players.m_skeleton ); ImGui::SameLine();
                    color_picker( "Skeleton Color", &cvar_players.m_skeleton_color );
                    ImGui::Checkbox( "Name", &cvar_players.m_name ); ImGui::SameLine();
                    color_picker( "Name Color", &cvar_players.m_name_color );
                    ImGui::Checkbox( "Distance", &cvar_players.m_distance ); ImGui::SameLine();
                    color_picker( "Distance Color", &cvar_players.m_distance_color );
                    ImGui::Checkbox( "Held Item", &cvar_players.m_held_item ); ImGui::SameLine();
                    color_picker( "Held Item Color", &cvar_players.m_held_item_color );
                    combo( "Held Item Type", &cvar_players.m_held_item_type, { "Text", "Icon" } );
                    ImGui::Checkbox( "Belt", &cvar_players.m_belt );
                    combo( "Belt Type", &cvar_players.m_belt_type, { "Single", "Multi" } );

                    ImGui::SliderInt( "Maximum Distance", &cvar_players.m_maximum_distance, 0, 500, "%dm" );

                    ImGui::EndTabItem();
                }

                if ( ImGui::BeginTabItem( "Scientists" ) ) {
                    ImGui::Checkbox( "Enabled", &cvar_scientists.m_enabled );
                    ImGui::Checkbox( "Box", &cvar_scientists.m_box ); ImGui::SameLine();
                    color_picker( "Box Color", &cvar_scientists.m_box_color );
                    ImGui::Checkbox( "Skeleton", &cvar_scientists.m_skeleton ); ImGui::SameLine();
                    color_picker( "Skeleton Color", &cvar_scientists.m_skeleton_color );
                    ImGui::Checkbox( "Name", &cvar_scientists.m_name ); ImGui::SameLine();
                    color_picker( "Name Color", &cvar_scientists.m_name_color );
                    ImGui::Checkbox( "Distance", &cvar_scientists.m_distance ); ImGui::SameLine();
                    color_picker( "Distance Color", &cvar_scientists.m_distance_color );
                    ImGui::Checkbox( "Held Item", &cvar_scientists.m_held_item ); ImGui::SameLine();
                    color_picker( "Held Item Color", &cvar_scientists.m_held_item_color );
                    combo( "Held Item Type", &cvar_scientists.m_held_item_type, { "Text", "Icon" } );
                    ImGui::Checkbox( "Belt", &cvar_scientists.m_belt );
                    combo( "Belt Type", &cvar_scientists.m_belt_type, { "Single", "Multi" } );

                    ImGui::SliderInt( "Belt FOV", &cvar_scientists.m_belt_fov, 0, 500, "%dpx" );
                    ImGui::SliderInt( "Maximum Distance", &cvar_scientists.m_maximum_distance, 0, 500, "%dm" );

                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }

            ImGui::End();
        }

        if ( players_msg ) {
            target_player = nullptr;
            target_distance = FLT_MAX;

            draw_players( players_msg->m_entities );         

            if ( target_player ) {

                float icon_width = 60.f * belt_lossy_scale.x;
                float icon_height = icon_width;

                float padding = 4.f * belt_lossy_scale.x;

                float x = floorf( belt_position.x - ( icon_width * 0.5f ) );
                float y = floorf( ( float )renderer.m_screen_size.y - ( belt_position.y + icon_height * 0.5f ) );

                y -= icon_height + padding;

                renderer.draw_string_w( x + ( ( icon_width + padding ) * 3.f ), y - 14.f,
                    fonts::verdana, 12.f, text_flags::centered | text_flags::drop_shadow, col32( 255, 255, 255, 255 ), target_player->m_name.str );

                for ( int i = 0; i < 6; i++ ) {
                    renderer.draw_filled_rect( x, y, icon_width, icon_height, col32( 140, 140, 255, 80 ) );

                    cached_belt_item& belt_item = target_player->m_belt_items[ i ];
                    if ( belt_item.m_present ) {
                        renderer.draw_image( x, y, icon_width, icon_height, col32( 255, 255, 255, 255 ), belt_item.m_localized_item->m_srv );
                    }

                    x += icon_width + padding;
                }
            }
        }

        renderer.end_frame();
    }
}