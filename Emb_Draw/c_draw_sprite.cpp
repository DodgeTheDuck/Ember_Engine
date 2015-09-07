
#include "c_draw_sprite.h"
#include "c_draw_texture.h"

namespace DRAW {

	Sprite::Sprite( Texture * texture, int cell, TYPE::point_f2 position, float scale )  {

		TYPE::size_i cellSize = texture->CellSize( );
		 
		_texIndex = texture->Index( );

		float left;
		float right;
		float top;
		float bottom;

		if( cellSize.w + cellSize.h > 0 ) {
			left = -( cellSize.w / 2.f ) + position.x;
			top = -( cellSize.h / 2.f ) + position.y;
			right = cellSize.w / 2 + position.x;
			bottom = cellSize.h / 2 + position.y;
		} else {
			TYPE::size_i size = texture->Size( );
			left = -( size.w / 2.f ) + position.x;
			top = -( size.h / 2.f ) + position.y;
			right = size.w / 2 + position.x;
			bottom = size.h / 2 + position.y;
		}

		TYPE::rect_f tex = texture->GetCoords( cell );

		float width = ( right - left ) * scale;
		float height = ( bottom - top ) * scale;

		AddVertex( ( new Vertex( ) )->Position( left, top )->Color( 1.0, 1.0, 1.0, 1.0 )->TexCoord( tex.left, tex.top ), 0 );
		AddVertex( ( new Vertex( ) )->Position( left, top + height )->Color( 1.0, 1.0, 1.0, 1.0 )->TexCoord( tex.left, tex.bottom ), 1 );
		AddVertex( ( new Vertex( ) )->Position( left + width, top + height )->Color( 1.0, 1.0, 1.0, 1.0 )->TexCoord( tex.right, tex.bottom ), 2 );

		AddVertex( NULL, 2 );
		AddVertex( ( new Vertex( ) )->Position( left + width, top )->Color( 1.0, 1.0, 1.0, 1.0 )->TexCoord( tex.right, tex.top ), 3 );
		AddVertex( NULL, 0 );
	}

}