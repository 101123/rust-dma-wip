#include "render.h"
#include "renderer.h"
#include "assets.h"

void render_thread() {
	while ( true ) {
		renderer.begin_frame();
		renderer.draw_string_a( 100.f, 100.f, fonts::verdana, 12.f, text_flags::centered | text_flags::outline, 0xFFFFFFFF, "Hello, world" );
		renderer.end_frame();
	}
}