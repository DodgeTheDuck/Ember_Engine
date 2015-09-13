#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>

namespace DRAW {

	class Shader {

		public:
		Shader( const char * fragment, const char * vertex );
		void UniformMatrix4( const char * name, const float * data );
		void UseProgram( );
		uint GetProgram( );
		private:
		unsigned int _fragIndex;
		unsigned int _vertIndex;
		unsigned int _programIndex;


	};

}
