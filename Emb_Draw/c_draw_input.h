#pragma once

#include "c_draw_defs.h"

namespace DRAW {

	class Window;

	struct EMB_DRAW_API  Controls {
		static bool left;
		static bool right;
		static bool forward;
		static bool backward;
		static bool fire;
		static long double mx;
		static long double my;
		static bool restart;
	};

	extern EMB_DRAW_API void InitInput( DRAW::Window * window );

}