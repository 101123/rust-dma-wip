#include "update.h"

#include "sdk.h"
#include "shared.h"
#include "engine.h"

#include <windows.h>

extern void update_bone_positions( fast_vector<cached_player>& players, scatter_request* scatter, bool initial_update = false );

static players* players_msg;

void update_thread() {
	scatter_request scatter;

	while ( true ) {
		players* msg = nullptr;
		while ( update_queue.try_pop( msg ) ) {
			players_msg = msg;
		}

		if ( players_msg ) {
			engine.update( &scatter );
			//engine.update( &scatter );
			//auto a = GetTickCount64();
			update_bone_positions( players_msg->m_entities, &scatter );
			//LOG( "%llu\n", GetTickCount64() - a );
		}
	}
}