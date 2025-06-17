#pragma once

#include <d3d11.h>
#include <cstdint>

class renderer {
public:
	bool initialize();

	void begin_frame();
	void end_frame();

	void draw_rect( float x, float y, float width, float height, float thickness, uint32_t color, float rounding = 1.f );
	void draw_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding = 1.f );
	void draw_circle( float x, float y, float radius, float thickness, uint32_t color );
	void draw_filled_circle( float x, float y, float radius, uint32_t color );
	void draw_line( float x1, float y1, float x2, float y2, float thickness, uint32_t color );
	void draw_string_a( float x, float y, float size, uint16_t flags, uint32_t color, const char* text );
	void draw_string_w( float x, float y, float size, uint16_t flags, uint32_t color, const wchar_t* text );
	void draw_image( float x, float y, float width, float height, ID3D11ShaderResourceView* srv );

	ID3D11ShaderResourceView* load_texture_from_memory( void* data, size_t size );

private:
	bool create_render_target();
	bool create_d3d_device();

	HWND m_hwnd;

	ID3D11Device* m_device;
	ID3D11DeviceContext* m_device_context;
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_render_target_view;
	ID3D11SamplerState* m_image_sampler;
};

inline renderer render;