#pragma once

#include "c_draw_defs.h"
#include <vector>
#include "c_draw_texture.h"

namespace DRAW {


	class EMB_DRAW_API TextureCache {
		
		public:

		void Push( Texture * texture );
		Texture * Get( unsigned int index );

		static TextureCache * Instance( );

		private:
		TextureCache( ) { };

		static TextureCache * _instance;
		std::vector< Texture* > _textures;

	};

}
