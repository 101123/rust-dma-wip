#include <imgui/imgui.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>

#include <d3d11.h>
#include <dwmapi.h>
#include <fstream>
#include <filesystem>

#include <iostream>
#include <vector>
#include <unordered_map>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define DEBUG

#include "renderer.h"
#include "asset_manager.h"

int main() {
    if ( !render.initialize() ) {
        std::cout << "Failed to intialize renderer!\n";
        return 1;
    }

    if ( !assets.load( "D:\\Repositories\\sundial\\x64\\Release\\assets.bin" ) ) {
        std::cout << "Failed to load assets!\n";
        return 2;
    }
    
    while ( true ) {
        render.begin_frame();

        render.draw_filled_rect( 100.f, 100.f, 90.f, 90.f, IM_COL32( 0, 0, 0, 128 ), 10.f );
        render.draw_image( 106.f, 106.f, 80.f, 80.f, assets.get_localized_item( 1545779598 )->m_srv );
        render.draw_string_a( 166.f, 166.f, 16.f, 0, IM_COL32_WHITE, "5x" );

        render.draw_circle( 300.f, 300.f, 100.f, 1.f, IM_COL32_WHITE );

        render.end_frame();
    }

    return 0;
}