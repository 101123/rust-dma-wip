#pragma once

#include <vector>
#include <string>
#include <d3d11.h>

enum locale : int {
    english,
    chinese,
    russian,
    locale_max
};

struct localized_item {
    int m_item_id;
    std::string m_translations[ locale::locale_max ];
    ID3D11ShaderResourceView* m_srv;
};

class asset_manager {
public:
    bool load( const char* file_path );

    localized_item* get_localized_item( int item_id );

private:
    std::vector<localized_item> m_localized_items;
};

inline asset_manager assets;