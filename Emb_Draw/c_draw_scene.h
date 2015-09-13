#pragma once

#include "c_draw_defs.h"
#include <c_type_general.h>
#include <vector>
#include <stack>

namespace DRAW {

	class Shader;
	class Camera;
	class Polytope;

	class EMB_DRAW_API Scene {

		public:

		enum e_Projection {
			DRAW_PROJ_PERSP,
			DRAW_PROJ_ORTHO
		};

		Scene( TYPE::size_i size );

		void Tick( );
		void Draw( );
		void SetProjection( e_Projection projection );
		void Translate( TYPE::point_f3 translation );
		void Rotate( float degrees, TYPE::point_f3 axis );
		void LoadIdentity( );
		float * GetModelMatrix( );
		void Clear( );
		Camera * GetCamera( );

		private:
		e_Projection _currentProj;
		TYPE::size_i _viewSpace;
		Shader * _sceneShader;
		Camera * _camera;
		std::vector<Polytope*> _polys;
		uint _nVerts;
		uint _nIndices;

	};

}