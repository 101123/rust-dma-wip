#include <json.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image_resize2.h>

#include <filesystem>
#include <fstream>
#include <unordered_map>

const char* localizations[] = {
	"localization/zh-cn.json",
	"localization/ru.json"
};

struct item {
	int item_id;
	std::string token;
	std::string english;
	std::string translated[ _countof( localizations ) ];
	uint8_t* image_data;
	int image_size;
};

std::vector<item> items;

std::unordered_map<int, std::string> item_id_to_token_map;

bool load_item_id_to_token_map() {
	std::ifstream stream( "assets/item_id_to_token.json" );
	if ( !stream.is_open() )
		return false;

	nlohmann::json json;

	try {
		json = nlohmann::json::parse( stream );
	} catch ( const nlohmann::json::parse_error& e ) {
		printf( "[!] failed to parse item id to token map\n" );
		return false;
	}

	for ( const auto& [ key, value ] : json.items() ) {
		item_id_to_token_map[ std::stoi( key ) ] = value;
	}

	return true;
}

class stream_writer {
public:
	stream_writer() : m_buffer(), m_position( 0ull ) {};

	template <typename T>
	void write( T data ) {
		m_buffer.resize( m_position + sizeof( T ) );
		memcpy( m_buffer.data() + m_position, &data, sizeof( T ) );
		m_position += sizeof( T );
	}

	void write( void* data, size_t size ) {
		m_buffer.resize( m_position + size );
		memcpy( m_buffer.data() + m_position, data, size );
		m_position += size;
	}

	void write( std::string string ) {
		// write size including null terminator
		write<uint16_t>( string.size() + 1 );

		// write string contents including null terminator
		write( ( void* )string.data(), string.size() + 1 );
	}

	std::vector<uint8_t>& data() {
		return m_buffer;
	}

	bool save_to_file( const char* file_name ) const {
		std::ofstream stream( file_name, std::ios::binary );
		if ( !stream.is_open() )
			return false;

		stream.write( ( const char* )m_buffer.data(), m_buffer.size() );
		return stream.good();
	}

private:
	std::vector<uint8_t> m_buffer;
	size_t m_position;
};

int main( int argc, char* argv[] ) {
	auto directory_iterator = std::filesystem::recursive_directory_iterator( "D:\\Games\\Steam\\steamapps\\common\\Rust\\Bundles\\items" );

	if ( !load_item_id_to_token_map() ) {
		printf( "[!] failed to load item id to token map\n" );
		return 1;
	}

	for ( const std::filesystem::directory_entry& directory_entry : directory_iterator ) {
		if ( directory_entry.path().extension() == ".json" ) {
			std::ifstream stream( directory_entry.path() );
			if ( !stream.is_open() ) {
				printf( "[!] failed to open %ws\n", directory_entry.path().filename().c_str() );
				continue;
			}

			nlohmann::json json;

			try {
				json = nlohmann::json::parse( stream );
			} catch ( const nlohmann::json::parse_error& e ) {
				printf( "[!] failed to parse %ws\n", directory_entry.path().filename().c_str() );
				stream.close();
				continue;
			}

			if ( !json.contains( "itemid" ) || !json.contains( "Name" ) ) {
				printf( "[!] failed to find keys in %ws\n", directory_entry.path().filename().c_str() );
				stream.close();
				continue;
			}

			int item_id = json[ "itemid" ];

			auto it = item_id_to_token_map.find( item_id );
			if ( it == item_id_to_token_map.end() ) {
				printf( "[!] failed to resolve token for %ws (%d)\n", directory_entry.path().filename().c_str(), item_id );
				stream.close();
				continue;
			}

			std::filesystem::path image_path = directory_entry.path();
			image_path.replace_extension( ".png" );
			std::filesystem::directory_entry image_directory_entry( image_path );

			if ( !image_directory_entry.exists() ) {
				printf( "[!] failed to find image for %ws\n", directory_entry.path().filename().c_str() );
				stream.close();
				continue;
			}

			std::ifstream image_stream( image_path, std::ios::binary );
			if ( !image_stream.is_open() ) {
				printf( "[!] failed to open %ws\n", image_path.filename().c_str() );
				stream.close();
				continue;
			}

			std::vector<uint8_t> image_data( image_directory_entry.file_size() );
			if ( !image_stream.read( ( char* )image_data.data(), image_data.size() ) ) {
				printf( "[!] failed to read %ws\n", image_path.filename().c_str() );
				stream.close();
				continue;
			}

			int image_width = 0, image_height = 0;
			unsigned char* image_pixel_data = stbi_load_from_memory( image_data.data(), image_data.size(), &image_width, &image_height, nullptr, 4);
			if ( !image_pixel_data ) {
				printf( "[!] failed to load %ws from memory\n", image_path.filename().c_str() );
				stream.close();
				continue;
			}

			const int resized_width = 128, resized_height = 128;
			uint8_t* resized_image = stbir_resize_uint8_srgb( image_pixel_data, image_width, image_height, 0, nullptr, resized_width, resized_height, 0, stbir_pixel_layout::STBIR_RGBA );
			if ( !resized_image ) {
				printf( "[!] failed to resize %ws\n", image_path.filename().c_str() );
				stream.close();
				continue;
			}

			items.push_back( {
				.item_id = item_id,
				.token = it->second,
				.english = json[ "Name" ],
				.translated = {},
				.image_data = resized_image,
				.image_size = resized_width * resized_height * 4
			} );

			stream.close();
			image_stream.close();
			stbi_image_free( image_pixel_data );
		}
	}

	printf( "[+] parsed %llu items\n", items.size() );

	for ( int i = 0; i < _countof( localizations ); i++ ) {
		std::ifstream stream( localizations[ i ] );
		if ( !stream.is_open() ) {
			printf( "[!] failed to open %s\n", localizations[ i ] );
			continue;
		}

		nlohmann::json json;

		try {
			json = nlohmann::json::parse( stream );
		} catch ( const nlohmann::json::parse_error& e ) {
			printf( "[!] failed to parse %s\n", localizations[ i ] );
			continue;
		}

		for ( item& item : items ) {
			if ( !json.contains( item.token ) ) {
				printf( "[!] %s doesn't contain %s\n", localizations[ i ], item.token.c_str() );
				continue;
			}

			item.translated[ i ] = json[ item.token ];
		}
	}

	stream_writer stream;

	// file version
	stream.write( 0 );
	stream.write( items.size() );

	for ( item& item : items ) {
		stream.write( item.item_id );
		stream.write( item.english );

		for ( const std::string& translated : item.translated ) {
			stream.write( translated );
		}

		stream.write( item.image_size );
		stream.write( item.image_data, item.image_size );

		free( item.image_data );
	}

	int padded_size = ( stream.data().size() + 3 ) & ~3;
	stream.data().resize( padded_size, 0 );

	uint32_t* data = ( uint32_t* )stream.data().data();

	for ( size_t i = 0; i < padded_size / 4; i++ ) {
		data[ i ] = data[ i ];
	}

	stream.save_to_file( "assets.bin" );
}