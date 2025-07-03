#pragma once

class mat4x4 {
public:
	float data[ 4 * 4 ];

	float operator[]( int index ) const { 
		return data[ index ]; 
	}

	float& operator[]( int index ) { 
		return data[ index ]; 
	}
};