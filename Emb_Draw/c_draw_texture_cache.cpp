
#include "c_draw_texture_cache.h"

namespace DRAW {

	TextureCache * TextureCache::_instance;

	void TextureCache::Push( Texture * texture ) {
		_textures.push_back( texture );
	}

	Texture * TextureCache::Get( unsigned int index ) {
		return _textures[index];
	}

	TextureCache * TextureCache::Instance( ) {
		if( !_instance ) _instance = new TextureCache( );
		return _instance;
	}

}