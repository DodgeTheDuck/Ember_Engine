
#include "c_draw_text.h"
#include "c_draw_batcher.h"
#include "c_draw_sprite.h"
#include "c_draw_texture_cache.h"

namespace DRAW {

	Text::Text( TYPE::string text, float scale, bool flip ) {

		for( int i = 0; i < text.length( ); i++ ) {

			int index = text[i] - 97;

			Batcher::Instance( )->Batch( new Sprite( TextureCache::Instance( )->Get( 0 ), index, { i * 8.0f * scale, 0 }, scale ) );

		}

	}

}