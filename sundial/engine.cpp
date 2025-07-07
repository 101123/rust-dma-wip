#include "engine.h"

void unity_engine::update( scatter_request* scatter ) {
    if ( !m_camera ) {
        camera* main_camera = main_camera::s_static_fields->main_camera;
        if ( main_camera ) {
            m_camera = main_camera->cached_ptr;
        }
    }

    if ( m_camera ) {
        m_camera_forward = vec3( m_view_matrix[ 2 ], m_view_matrix[ 5 ], m_view_matrix[ 9 ] );
        m_camera_yaw = atan2f( m_camera_forward.x, m_camera_forward.z );

        scatter->add_field( &m_camera->view_matrix, &m_view_matrix );
        scatter->add_field( &m_camera->position, &m_camera_position );
    }
}

bool unity_engine::w2s( vec3* world, vec2* screen ) {
    float w = dot( vec3( m_view_matrix[ 3 ], m_view_matrix[ 7 ], m_view_matrix[ 11 ] ), *world ) + m_view_matrix[ 15 ];
    if ( w < 0.098f )
        return false;

    *screen = vec2(
        ( 2560.f * 0.5f ) * ( 1.f + ( dot( vec3( m_view_matrix[ 0 ], m_view_matrix[ 4 ], m_view_matrix[ 8 ] ), *world ) + m_view_matrix[ 12 ] ) / w ),
        ( 1440.f * 0.5f ) * ( 1.f - ( dot( vec3( m_view_matrix[ 1 ], m_view_matrix[ 5 ], m_view_matrix[ 9 ] ), *world ) + m_view_matrix[ 13 ] ) / w )
    ) + vec2( 0.f, 0.f );

    return true;
}

bool unity_engine::w2s( vec3* world ) {
    float w = dot( vec3( m_view_matrix[ 3 ], m_view_matrix[ 7 ], m_view_matrix[ 11 ] ), *world ) + m_view_matrix[ 15 ];
    if ( w < 0.098f )
        return false;

    return true;
}