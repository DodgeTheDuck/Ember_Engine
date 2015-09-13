#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>

namespace DRAW {

	class Camera {

		public:
		Camera( TYPE::point_f3 position );
		void Move( float dx, float dy, float dz = 0 );
		TYPE::point_f3 GetPosition( );
		
		float * GetViewMatrix( );

		private:
		TYPE::point_f3 _position;

	};

}