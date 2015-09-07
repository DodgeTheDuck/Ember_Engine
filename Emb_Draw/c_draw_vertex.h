#pragma once

#define VERT_POS_SIZE 3
#define VERT_COL_SIZE 4
#define VERT_TEX_SIZE 2

#include <c_type_general.h>

//###########################################################################################################
//# NOTES:
//# 
//#	~ size = 32 bytes
//#

namespace DRAW {

	struct Vertex {

		public:
		float			pos[3];
		float			col[4];
		float			tex[2];

		Vertex * Position( float x, float y, float z = 0 ) { pos[0] = x; pos[1] = y; pos[2] = z; return this; };
		Vertex * Color( float r, float g, float b, float a = 1.0 ) { col[0] = r; col[1] = g; col[2] = b; col[3] = a; return this; };
		Vertex * Color( TYPE::color_f4 color ) { col[0] = color.r; col[1] = color.g; col[2] = color.b; col[3] = color.a; return this; };
		Vertex * TexCoord( float x, float y ) { tex[0] = x; tex[1] = y; return this; };

	};


}
