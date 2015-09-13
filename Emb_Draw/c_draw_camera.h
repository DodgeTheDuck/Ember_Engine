#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>

namespace DRAW {

	class EMB_DRAW_API Camera {

		public:
		Camera( TYPE::point_f3 position );
		void Move( real dx, real dy, real dz = 0 );
		void MoveLocal( real angle, real speed );
		void Rotate( real angle, TYPE::point_f3 axis );
		void MouseLook( );
		TYPE::point_f3 GetPosition( );
		TYPE::point_f3 GetRotation( );

		private:
		TYPE::point_f3 _position;
		
	};

}