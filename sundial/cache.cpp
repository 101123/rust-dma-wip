#include "cache.h"

#include "sdk.h"
#include "global.h"
#include "il2cpp.h"

BufferList<BaseNetworkable*>* cached_entity_list;
BufferList<BasePlayer*>* cached_player_list;

bool populate_entity_lists() {
	if ( !cached_entity_list ) {
		auto client_entities_hidden_value = BaseNetworkable::static_fields->clientEntities.value;
		if ( client_entities_hidden_value ) {
			BaseNetworkable::EntityRealm* client_entities = nullptr;
			if ( il2cpp_gchandle_get_target( client_entities_hidden_value->_handle, &client_entities ) ) {
				auto entity_list_hidden_value = client_entities->entityList.value;
				if ( entity_list_hidden_value ) {
					ListDictionary<uint64_t, BaseNetworkable*>* entity_list = nullptr;
					if ( il2cpp_gchandle_get_target( entity_list_hidden_value->_handle, &entity_list ) ) {
						BufferList<BaseNetworkable*>* vals = entity_list->vals;
						// Validate that list is currently valid before we cache
						if ( vals ) {
							Array<BaseNetworkable*>* buffer = vals->buffer;
							int count = vals->count;
							if ( buffer && count > 0 && count < 65536 ) {
								cached_entity_list = vals;
							}
						}
					}
				}
			}
		}
	}

	if ( !cached_player_list ) {

	}

	return cached_entity_list != nullptr;
}

void cache_thread() {
	cache_thread_running = true;

	populate_entity_lists();

	cache_thread_running = false;
}