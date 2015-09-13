#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>

namespace DRAW {

	class Window;

	namespace INPUT {

		struct EMB_DRAW_API  Controls {
			static bool left;
			static bool right;
			static bool forward;
			static bool backward;
			static bool fire;
			static long double mx;
			static long double my;
			static bool restart;
			static Window * context;
		};

		extern EMB_DRAW_API void Init( DRAW::Window * window );
		extern EMB_DRAW_API void CenterMouse( );
		extern EMB_DRAW_API void SetMousePosition( TYPE::point_f2 pos );

	}

}