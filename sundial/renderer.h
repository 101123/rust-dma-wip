#pragma once

#include <math/vec2.h>

#include <d3d11.h>
#include <cstdint>

#define col32( r, g, b, a ) ( ( ( uint32_t )( a ) << 24 ) | ( ( uint32_t )( b ) << 16 ) | ( ( uint32_t ) ( g ) << 8 ) | ( ( uint32_t )( r ) << 0 ) )

enum fonts {
	verdana,
	icon
};

enum text_flags {
	centered = 1,
	drop_shadow = 2,
	outline = 4
};

class renderer_manager {
public:
	bool initialize();

	void begin_frame( bool receive_input );
	void end_frame();

	void draw_rect( float x, float y, float width, float height, float thickness, uint32_t color, float rounding = 0.f );
	void draw_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding = 0.f );
	void draw_circle( float x, float y, float radius, float thickness, uint32_t color );
	void draw_filled_circle( float x, float y, float radius, uint32_t color );
	void draw_line( float x1, float y1, float x2, float y2, float thickness, uint32_t color );
	void draw_string_a( float x, float y, uint32_t font, float size, uint32_t flags, uint32_t color, const char* text );
	void draw_string_w( float x, float y, uint32_t font, float size, uint32_t flags, uint32_t color, const wchar_t* text );
	void draw_image( float x, float y, float width, float height, ID3D11ShaderResourceView* srv );

	ID3D11ShaderResourceView* load_texture_from_memory( void* image_data, uint32_t image_width, uint32_t image_height );

	bool create_render_target();
	bool create_d3d_device();

	vec2i m_screen_size;
	HWND m_hwnd;

	ID3D11Device* m_device;
	ID3D11DeviceContext* m_device_context;
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_render_target_view;
	ID3D11SamplerState* m_image_sampler;

	void* m_fonts[ 8 ];
};

inline renderer_manager renderer;