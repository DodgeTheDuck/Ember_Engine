#pragma once

#include "c_draw_defs.h"
#include "c_draw_polytope.h"

namespace DRAW {

	class Texture;

	class EMB_DRAW_API Sprite : public Polytope {

		public:
		Sprite( Texture * texture, int cell = 0, TYPE::point_f2 position = { 0, 0 }, float scale = 1.0 );
		~Sprite( );

	};

}