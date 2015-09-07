
#include "c_draw_polytope.h"
#include <algorithm>

namespace DRAW {

	Polytope::Polytope( ) {

	}

	void Polytope::AddVertex( Vertex * vertex, uint index ) {
		if( vertex ) _vertices.push_back( vertex );
		_indices.push_back( index );
	}

	s_polyData * Polytope::GetData( ) {
		s_polyData * data = new s_polyData( _vertices.size( ), _indices.size( ) );
		for( int i = 0; i < _vertices.size( ); i++ ) {
			unsigned int posIndex = i * VERT_POS_SIZE;
			unsigned int colIndex = i * VERT_COL_SIZE;
			unsigned int texIndex = i * VERT_TEX_SIZE;
			memcpy( &data->point[posIndex], &_vertices[i]->pos, sizeof( float ) * VERT_POS_SIZE );
			memcpy( &data->color[colIndex], &_vertices[i]->col, sizeof( float ) * VERT_COL_SIZE );
			memcpy( &data->tex[texIndex],	&_vertices[i]->tex, sizeof( float ) * VERT_TEX_SIZE );
		}
		memcpy( &data->indices[0], &_indices[0], sizeof( uint ) * _indices.size( ) );
		return data;
	}

	uint Polytope::VertCount( ) {
		return _vertices.size( );
	}

	uint Polytope::IndexCount( ) {
		return _indices.size( );
	}

	uint Polytope::TextureIndex( ) {
		return _texIndex;
	}

	Polytope::~Polytope( ) {

	}

}