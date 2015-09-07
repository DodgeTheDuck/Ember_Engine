#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>

namespace DRAW {

	class Window;

	class EMB_DRAW_API Setup {

		public:
		static void InitStart( );
		static void InitEnd( );
		static void SetVSync( bool value );
		static void SetRenderContext( Window * context );
		static void SetClearColor( TYPE::color_f4 color );

	};

};
