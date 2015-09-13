#pragma once

#include "c_draw_defs.h"
#include "c_draw_polytope.h"
#include "c_draw_texture.h"
#include <c_type_general.h>

namespace DRAW {

	class PRect : public Polytope {

		public:

		PRect( float left, float up, float right, float down, TYPE::color_f4 color = { 1.0, 1.0, 1.0, 1.0 } ) {

			AddVertex( ( new Vertex( ) )->Position( left, up )->Color( color )->TexCoord( 0, 0 ), 0 );
			AddVertex( ( new Vertex( ) )->Position( left, down )->Color( color )->TexCoord( 0, 1 ), 1 );
			AddVertex( ( new Vertex( ) )->Position( right, down )->Color( color )->TexCoord( 1, 1 ), 2 );

			AddVertex( NULL, 2 );
			AddVertex( ( new Vertex( ) )->Position( right, up )->Color( color )->TexCoord( 1, 0 ), 3 );
			AddVertex( NULL, 0 );

			_texIndex = 0;

		}

	};

	class PCube : public Polytope {

		public:
		PCube( TYPE::point_f3 position, float scale, Texture * texture, TYPE::color_f4 color = { 1.0, 1.0, 1.0, 1.0 } ) {

			// FRONT
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y - scale, position.z - scale )->Color( color )->TexCoord( 0, 0 ), 0 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y + scale, position.z - scale )->Color( color )->TexCoord( 0, 1 ), 1 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y + scale, position.z - scale )->Color( color )->TexCoord( 1, 1 ), 2 );
			AddVertex( NULL, 2 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y - scale, position.z - scale )->Color( color )->TexCoord( 1, 0 ), 3 );
			AddVertex( NULL, 0 );

			// BACK
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y - scale, position.z + scale )->Color( color )->TexCoord( 0, 0 ), 4 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y + scale, position.z + scale )->Color( color )->TexCoord( 0, 1 ), 5 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y + scale, position.z + scale )->Color( color )->TexCoord( 1, 1 ), 6 );
			AddVertex( NULL, 6 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y - scale, position.z + scale )->Color( color )->TexCoord( 1, 0 ), 7 );
			AddVertex( NULL, 4 );

			// LEFT
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y - scale, position.z - scale )->Color( color )->TexCoord( 0, 0 ), 8 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y - scale, position.z + scale )->Color( color )->TexCoord( 0, 1 ), 9 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y + scale, position.z + scale )->Color( color )->TexCoord( 1, 1 ), 10 );
			AddVertex( NULL, 10 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y + scale, position.z - scale )->Color( color )->TexCoord( 1, 0 ), 11 );
			AddVertex( NULL, 8 );

			// RIGHT
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y - scale, position.z - scale )->Color( color )->TexCoord( 0, 0 ), 12 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y - scale, position.z + scale )->Color( color )->TexCoord( 0, 1 ), 13 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y + scale, position.z + scale )->Color( color )->TexCoord( 1, 1 ), 14 );
			AddVertex( NULL, 14 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y + scale, position.z - scale )->Color( color )->TexCoord( 1, 0 ), 15 );
			AddVertex( NULL, 12 );

			// BOTTOM
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y - scale, position.z - scale )->Color( color )->TexCoord( 0, 0 ), 16 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y - scale, position.z + scale )->Color( color )->TexCoord( 0, 1 ), 17 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y - scale, position.z + scale )->Color( color )->TexCoord( 1, 1 ), 18 );
			AddVertex( NULL, 18 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y - scale, position.z - scale )->Color( color )->TexCoord( 1, 0 ), 19 );
			AddVertex( NULL, 16 );

			// TOP
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y + scale, position.z - scale )->Color( color )->TexCoord( 0, 0 ), 20 );
			AddVertex( ( new Vertex( ) )->Position( position.x - scale, position.y + scale, position.z + scale )->Color( color )->TexCoord( 0, 1 ), 21 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y + scale, position.z + scale )->Color( color )->TexCoord( 1, 1 ), 22 );
			AddVertex( NULL, 22 );
			AddVertex( ( new Vertex( ) )->Position( position.x + scale, position.y + scale, position.z - scale )->Color( color )->TexCoord( 1, 0 ), 23 );
			AddVertex( NULL, 20 );


			_texIndex = texture->Index( );

		}

	};

}