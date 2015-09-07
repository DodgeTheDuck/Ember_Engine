#pragma once

#include "c_draw_defs.h"
#include "c_draw_polytope.h"
#include <c_type_general.h>

namespace DRAW {

	class EMB_DRAW_API Text {

		public:
		Text( TYPE::string text, float scale = 1.0, bool flip = false );

	};

}