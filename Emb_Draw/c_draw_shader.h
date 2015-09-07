#pragma once

#include "c_draw_defs.h"

namespace DRAW {

	class Shader {

		public:
		Shader( const char * fragment, const char * vertex );
		void UniformMatrix4( const char * name, const float * data );
		void UseProgram( );
		private:
		unsigned int _fragIndex;
		unsigned int _vertIndex;
		unsigned int _programIndex;


	};

}
