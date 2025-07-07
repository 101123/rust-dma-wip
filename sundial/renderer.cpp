#include "renderer.h"
#include "fonts.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_freetype.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <dwmapi.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

LRESULT CALLBACK wnd_proc( HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param ) {
    if ( ImGui_ImplWin32_WndProcHandler( hwnd, msg, w_param, l_param ) )
        return true;

    return DefWindowProcA( hwnd, msg, w_param, l_param );
}

template <typename T>
void clean_up( T ptr ) {
    if ( ptr ) {
        ptr->Release();
        ptr = nullptr;
    }
}

bool renderer_manager::create_render_target() {
    ID3D11Texture2D* back_buffer = nullptr;
    if ( m_swap_chain->GetBuffer( 0, IID_PPV_ARGS( &back_buffer ) ) != S_OK )
        return false;

    bool result = m_device->CreateRenderTargetView( back_buffer, nullptr, &m_render_target_view ) == S_OK;
    back_buffer->Release();
    return result;
}

bool renderer_manager::create_d3d_device() {
    DXGI_SWAP_CHAIN_DESC swap_chain_descriptor {
        .BufferDesc = {
            .Width = 0,
            .Height = 0,
            .RefreshRate = {
                .Numerator = 60,
                .Denominator = 1
            },

            .Format = DXGI_FORMAT_R8G8B8A8_UNORM,
            .ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
            .Scaling = DXGI_MODE_SCALING_UNSPECIFIED
        },

        .SampleDesc = {
            .Count = 1,
            .Quality = 0
        },

        .BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
        .BufferCount = 2,
        .OutputWindow = m_hwnd,
        .Windowed = true,
        .SwapEffect = DXGI_SWAP_EFFECT_DISCARD,
        .Flags = 0
    };

    D3D_FEATURE_LEVEL feature_levels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
    };

    HRESULT result = D3D11CreateDeviceAndSwapChain( nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
        feature_levels, _countof( feature_levels ), D3D11_SDK_VERSION, &swap_chain_descriptor, &m_swap_chain, &m_device, nullptr, &m_device_context );

    if ( result == DXGI_ERROR_UNSUPPORTED ) {
        result = D3D11CreateDeviceAndSwapChain( nullptr, D3D_DRIVER_TYPE_WARP, nullptr, 0,
            feature_levels, _countof( feature_levels ), D3D11_SDK_VERSION, &swap_chain_descriptor, &m_swap_chain, &m_device, nullptr, &m_device_context );
    }

    if ( result != S_OK )
        return false;

    return create_render_target();
}

bool renderer_manager::initialize() {
    WNDCLASS wnd_class {
        .style = CS_VREDRAW | CS_HREDRAW,
        .lpfnWndProc = wnd_proc,
        .cbClsExtra = 0,
        .cbWndExtra = 0,
        .hInstance = GetModuleHandleA( nullptr ),
        .hIcon = LoadIconA( nullptr, IDI_APPLICATION ),
        .hCursor = LoadCursorA( nullptr, IDC_ARROW ),
        .hbrBackground = CreateSolidBrush( RGB( 0, 0, 0 ) ),
        .lpszMenuName = nullptr,
        .lpszClassName = "sundial"
    };

    RegisterClassA( &wnd_class );

    m_screen_size = vec2i( 
        GetSystemMetrics( SM_CXSCREEN ), 
        GetSystemMetrics( SM_CYSCREEN ) 
    );

    m_hwnd = CreateWindowExA(
        WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED,
        wnd_class.lpszClassName,
        "sundial",
        WS_POPUP,
        0,
        0,
        m_screen_size.x,
        m_screen_size.y,
        nullptr,
        nullptr,
        wnd_class.hInstance,
        nullptr
    );

    SetLayeredWindowAttributes( m_hwnd, 0, 255, LWA_ALPHA );

    MARGINS margins = {
        .cxLeftWidth = -1,
        .cxRightWidth = 0,
        .cyTopHeight = 0,
        .cyBottomHeight = 0
    };

    DwmExtendFrameIntoClientArea( m_hwnd, &margins );

    if ( !create_d3d_device() ) {
        // TODO: cleanup
        return false;
    }

    ShowWindow( m_hwnd, SW_SHOWDEFAULT );
    UpdateWindow( m_hwnd );

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // stop .ini files from being created
    io.IniFilename = nullptr;

    // load fonts
    ImFontConfig cfg = {};
    cfg.FontLoaderFlags = ImGuiFreeTypeLoaderFlags_LightHinting;

    m_fonts[ fonts::verdana ] = io.Fonts->AddFontFromFileTTF( "C:\\Windows\\Fonts\\verdana.ttf", 0.f, &cfg );
    m_fonts[ fonts::icon ] = io.Fonts->AddFontFromMemoryCompressedTTF( icon_font_compressed_data, icon_font_compressed_size, 13.f );

    if ( !ImGui_ImplWin32_Init( m_hwnd ) ) {
        // TODO: cleanup
        return false;
    }

    if ( !ImGui_ImplDX11_Init( m_device, m_device_context ) ) {
        // TODO: cleanup
        return false;
    }

    D3D11_SAMPLER_DESC sampler_desc {
        .Filter = D3D11_FILTER_ANISOTROPIC,
        .AddressU = D3D11_TEXTURE_ADDRESS_CLAMP,
        .AddressV = D3D11_TEXTURE_ADDRESS_CLAMP,
        .AddressW = D3D11_TEXTURE_ADDRESS_CLAMP,
        .MipLODBias = -0.3f,
        .MaxAnisotropy = 4,
        .ComparisonFunc = D3D11_COMPARISON_ALWAYS,
        .BorderColor = { 0.f, 0.f, 0.f, 0.f },
        .MinLOD = 0,
        .MaxLOD = D3D11_FLOAT32_MAX
    };

    if ( m_device->CreateSamplerState( &sampler_desc, &m_image_sampler ) ) {
        // TODO: cleanup
        return false;
    }

    return true;
}

void renderer_manager::begin_frame( bool receive_input ) {
    LONG flags = WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED;

    if ( receive_input ) {
        MSG msg;
        while ( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) ) {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }

        flags &= ~WS_EX_LAYERED;
    }

    SetWindowLong( m_hwnd, GWL_EXSTYLE, flags );

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void renderer_manager::end_frame() {
    const float transparent[ 4 ] = { 0.f, 0.f, 0.f, 0.f };

    ImGui::Render();

    m_device_context->OMSetRenderTargets( 1, &m_render_target_view, nullptr );
    m_device_context->ClearRenderTargetView( m_render_target_view, transparent );

    ImGui_ImplDX11_RenderDrawData( ImGui::GetDrawData() );

    m_swap_chain->Present( 0, 0 );
}

void renderer_manager::draw_rect( float x, float y, float width, float height, float thickness, uint32_t color, float rounding ) {
    ImGui::GetForegroundDrawList()->AddRect( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding, ImDrawFlags_None, thickness );
}

void renderer_manager::draw_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding ) {
    ImGui::GetForegroundDrawList()->AddRectFilled( ImVec2( x, y ), ImVec2( x + width, y + height ), color, rounding );
}

void renderer_manager::draw_circle( float x, float y, float radius, float thickness, uint32_t color ) {
    ImGui::GetForegroundDrawList()->AddCircle( ImVec2( x, y ), radius, color, 0, thickness );
}

void renderer_manager::draw_filled_circle( float x, float y, float radius, uint32_t color ) {
    ImGui::GetForegroundDrawList()->AddCircleFilled( ImVec2( x, y ), radius, color );
}

void renderer_manager::draw_line( float x1, float y1, float x2, float y2, float thickness, uint32_t color ) {
    ImGui::GetForegroundDrawList()->AddLine( ImVec2( x1, y1 ), ImVec2( x2, y2 ), color, thickness );
}

void renderer_manager::draw_string_a( float x, float y, uint32_t font_idx, float size, uint32_t flags, uint32_t color, const char* text ) {
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    ImFont* font = ( ImFont* )m_fonts[ font_idx ];

    if ( flags & text_flags::centered ) {
        ImVec2 bounds = font->CalcTextSizeA( size, FLT_MAX, 0.f, text );
        x -= bounds.x * 0.5f;
    }

    uint32_t outline_color = IM_COL32( 0, 0, 0, 100 );

    if ( flags & ( text_flags::drop_shadow | text_flags::outline ) ) {
        draw_list->AddText( font, size, ImVec2( x + 1.f, y + 1.f ), outline_color, text );
    }

    if ( flags & text_flags::outline ) {
        draw_list->AddText( font, size, ImVec2( x - 1.f, y - 1.f ), outline_color, text );
        draw_list->AddText( font, size, ImVec2( x + 1.f, y - 1.f ), outline_color, text );
        draw_list->AddText( font, size, ImVec2( x - 1.f, y + 1.f ), outline_color, text );
        draw_list->AddText( font, size, ImVec2( x + 1.f, y ), outline_color, text );
        draw_list->AddText( font, size, ImVec2( x - 1.f, y ), outline_color, text );
        draw_list->AddText( font, size, ImVec2( x, y - 1.f ), outline_color, text );
        draw_list->AddText( font, size, ImVec2( x, y + 1.f ), outline_color, text );
    }

    draw_list->AddText( font, size, ImVec2( x, y ), color, text );
}

void renderer_manager::draw_string_w( float x, float y, uint32_t font_idx, float size, uint32_t flags, uint32_t color, const wchar_t* text ) {
    char buffer[ 512 ];
    ImTextStrToUtf8( buffer, sizeof( buffer ), ( ImWchar* )text, ( ImWchar* )( text + wcslen( text ) + 1 ) );

    draw_string_a( x, y, font_idx, size, flags, color, buffer );
}

void draw_image_callback( const ImDrawList* parent_list, const ImDrawCmd* cmd ) {
    ImGui_ImplDX11_RenderState* render_state = ( ImGui_ImplDX11_RenderState* )ImGui::GetPlatformIO().Renderer_RenderState;
    ID3D11SamplerState* sampler = cmd->UserCallbackData ? ( ID3D11SamplerState* )cmd->UserCallbackData : render_state->SamplerDefault;
    render_state->DeviceContext->PSSetSamplers( 0, 1, &sampler );
}

void renderer_manager::draw_image( float x, float y, float width, float height, ID3D11ShaderResourceView* srv ) {
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();

    draw_list->AddCallback( draw_image_callback, m_image_sampler );
    draw_list->AddImage( srv, ImVec2( x, y ), ImVec2( x + width, y + height ) );
    draw_list->AddCallback( draw_image_callback, nullptr );
}

ID3D11ShaderResourceView* renderer_manager::load_texture_from_memory( void* image_data, uint32_t image_width, uint32_t image_height ) {
    D3D11_TEXTURE2D_DESC texture_desc {
        .Width = image_width,
        .Height = image_height,
        .MipLevels = 0,
        .ArraySize = 1,
        .Format = DXGI_FORMAT_R8G8B8A8_UNORM,
        .SampleDesc = {
            .Count = 1,
            .Quality = 0
        },

        .Usage = D3D11_USAGE_DEFAULT,
        .BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET,
        .CPUAccessFlags = 0,
        .MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS
    };

    ID3D11Texture2D* texture = nullptr;
    if ( m_device->CreateTexture2D( &texture_desc, nullptr, &texture ) != S_OK )
        return nullptr;

    m_device_context->UpdateSubresource( texture, 0, nullptr, image_data, image_width * 4, 0 );

    D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc {
        .Format = texture_desc.Format,
        .ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D,
        .Texture2D = {
            .MostDetailedMip = 0,
            .MipLevels = ( uint32_t )-1
        }
    };

    ID3D11ShaderResourceView* srv = nullptr;
    if ( m_device->CreateShaderResourceView( texture, &srv_desc, &srv ) != S_OK ) {
        texture->Release();
        return nullptr;
    }

    m_device_context->GenerateMips( srv );
    texture->Release();
    return srv;
}