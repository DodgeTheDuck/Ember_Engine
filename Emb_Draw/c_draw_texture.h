#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>

namespace DRAW {

	class EMB_DRAW_API Texture {

		public:
		Texture( char * filename, TYPE::size_i cellSize = { 0, 0 }, uint sep = 0 );
		uint Index( );
		TYPE::size_i CellSize( );
		TYPE::size_i Size( );
		TYPE::rect_f GetCoords( uint cell = 0 );
		void Bind( );
		private:
		unsigned int _texIndex;
		TYPE::size_i _size;
		TYPE::size_i _cellSize;
		uint _sep;
	};

}
