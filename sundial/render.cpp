#include "render.h"
#include "renderer.h"
#include "asset_manager.h"

void render_thread() {
	while ( true ) {
		render.begin_frame();
		render.draw_string_a( 100.f, 100.f, fonts::verdana, 12.f, text_flags::centered | text_flags::outline, 0xFFFFFFFF, "Hello, world" );
		render.end_frame();
	}
}