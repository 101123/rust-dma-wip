#include "asset_manager.h"
#include "stream_reader.h"
#include "renderer.h"

#include <filesystem>
#include <fstream>

bool asset_manager::load( const char* file_path ) {
	std::filesystem::directory_entry assets( file_path );
	if ( !assets.exists() )
		return false;

	std::ifstream fstream( assets.path(), std::ios::binary );
	if ( !fstream.is_open() )
		return false;

	std::vector<uint8_t> data( assets.file_size() );
	if ( !fstream.read( ( char* )data.data(), data.size() ) ) {
	    fstream.close();
	    return false;
	}

	stream_reader stream( data );

	int version = stream.read<int>();
	size_t item_count = stream.read<size_t>();
	
	for ( size_t i = 0; i < item_count; i++ ) {
		localized_item& item = m_localized_items.emplace_back();
	
	    item.m_item_id = stream.read<int>();
	
	    for ( size_t j = 0; j < _countof( item.m_translations ); j++ ) {
	        item.m_translations[ j ] = stream.read_string();
	    }
	
	    size_t image_size = stream.read<size_t>();
	    void* image = stream.read( image_size );
	
	    item.m_srv = render.load_texture_from_memory( image, image_size );
	}
	
	fstream.close();

	return true;
}

localized_item* asset_manager::get_localized_item( int item_id ) {
	for ( localized_item& localized_item : m_localized_items ) {
		if ( item_id == localized_item.m_item_id ) {
			return &localized_item;
		}
	}

	return nullptr;
}