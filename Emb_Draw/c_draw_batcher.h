#pragma once

#include <vector>
#include <c_type_general.h>
#include "c_draw_defs.h"

namespace DRAW {

	class Polytope;
	class Object;
	class Scene;

	struct s_batch {

		Object * object;
		uint texture;
		~s_batch( ) { delete( object ); };

	};

	class EMB_DRAW_API Batcher {

		public:

		void Batch( Polytope * poly );
		s_batch * GetBatch( uint index );
		void DrawAll( );
		uint Count( );
		void Clear( );

		static Batcher * Instance( );

		private:
		s_batch * CreateBatch( uint textureIndex );
		Batcher( ) { };
		static Batcher * _instance;
		std::vector<s_batch*> _batches;
	};

}
