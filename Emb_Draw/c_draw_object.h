#pragma once

#include "c_draw_defs.h"
#include "c_draw_vertex.h"
#include "c_draw_polytope.h"

namespace DRAW {

	class EMB_DRAW_API Object {

		public:

		Object( );
		~Object( );

		void AddData( s_polyData * data );

		void BuildVAO( );
		void Draw( );
		
		void * GetMappedBuffer( );

		void AllocateMemory( uint n_verts, uint n_indices );

		private:

		unsigned int _vaoIndex;

		unsigned int _elementVBO;
		unsigned int _pointVBO;
		unsigned int _texVBO;
		unsigned int _colVBO;

		uint			* _elements;
		float			* _points;
		float			* _tex;
		float			* _cols;

		unsigned int _n_verts;
		unsigned int _n_indices;

	};

}