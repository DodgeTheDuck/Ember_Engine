
#pragma once

#include "c_draw_defs.h"
#include "c_draw_vertex.h"
#include <vector>

namespace DRAW {

	struct EMB_DRAW_API s_polyData {
		s_polyData( uint nVerts, uint nIndices ) { AllocateMemory( nVerts, nIndices ); }
		float * point;
		float * color;
		float * tex;
		uint * indices;
		uint indexCount;
		uint vertCount;
		void AllocateMemory( uint nVerts, uint nIndices ) {
			point = (float*) calloc( nVerts * VERT_POS_SIZE, sizeof( float ) );
			color = (float*) calloc( nVerts * VERT_COL_SIZE, sizeof( float ) );
			tex = (float*) calloc( nVerts * VERT_TEX_SIZE, sizeof( float ) );
			indices = (uint*) calloc( nIndices, sizeof( uint ) );
			vertCount = nVerts;
			indexCount = nIndices;
		}
	};

	class EMB_DRAW_API Polytope {

		public:

		Polytope( );
		~Polytope( );

		virtual void AddVertex( Vertex * vert, uint index );
		virtual uint IndexCount( );
		virtual uint VertCount( );
		virtual uint TextureIndex( );

		virtual s_polyData * GetData( );

		protected:
		uint _texIndex;

		private:
		std::vector< Vertex * > _vertices;
		std::vector< uint > _indices;


	};

}
