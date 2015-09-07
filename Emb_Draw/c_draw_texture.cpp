
#include "c_draw_texture.h"
#include "lodepng.h"
#include <iostream>
#include <GLFW\glfw3.h>

namespace DRAW {

	Texture::Texture( char * filename, TYPE::size_i cellSize, uint sep ) {

		_cellSize = cellSize;
		_sep = sep;

		std::vector<unsigned char>	pixels;

		uint w = 0;
		uint h = 0;

		unsigned error = lodepng::decode( pixels, w, h, filename );

		if( error ) {
			std::cout << lodepng_error_text( error ) << std::endl;
			return;
		} else {

			_size.w = w;
			_size.h = h;

			glGenTextures( 1, &_texIndex );
			glBindTexture( GL_TEXTURE_2D, _texIndex );

			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0] );

			glBindTexture( GL_TEXTURE_2D, 0 );

		}

	}

	TYPE::size_i Texture::CellSize( ) {
		return _cellSize;
	}

	TYPE::size_i Texture::Size( ) {
		return _size;
	}


	uint Texture::Index( ) {
		return _texIndex;
	}

	TYPE::rect_f Texture::GetCoords( uint cell ) {

		float pxx = 0;
		float pxy = 0;
		float pxw = 1;
		float pxh = 1;

		if( _cellSize.w + _cellSize.h > 0 ) {

			int cols = _size.w / ( _cellSize.w + _sep + 1 ) + 1;
			int rows = _size.h / ( _cellSize.h + _sep + 1 ) + 1;

			int x = cell % cols;
			int y = cell / cols;

			float pw = 1.0 / _size.w;
			float ph = 1.0 / _size.h;

			pxx = ( pw * x * _cellSize.w ) + ( pw * ( x * _sep ) + ( pw * _sep ) );
			pxy = ( ph * y * _cellSize.h ) + ( ph * ( y * _sep ) + ( ph * _sep ) );
			pxw = pxx + ( pw * _cellSize.w );
			pxh = pxy + ( ph * _cellSize.h );

		}

		return TYPE::rect_f{
			pxx,
			pxy,
			pxw,
			pxh
		};

	}

	void Texture::Bind( ) {
		glBindTexture( GL_TEXTURE_2D, _texIndex );
	}

}