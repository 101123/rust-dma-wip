#include "update.h"

#include "sdk.h"
#include "shared.h"
#include "engine.h"

#include <windows.h>

extern void update_bone_positions( fast_vector<player>& players, scatter_request* scatter );

static players* players_msg;

void update_thread() {
	scatter_request scatter;

	while ( true ) {
		players* msg = nullptr;
		while ( update_queue.try_pop( msg ) ) {
			players_msg = msg;
		}

		if ( players_msg ) {
			//engine.update( &scatter );
			//auto a = GetTickCount64();
			update_bone_positions( players_msg->m_players, &scatter );
			//LOG( "%llu\n", GetTickCount64() - a );
		}
	}
}