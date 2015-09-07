
#include "c_draw_batcher.h"
#include "c_draw_polytope.h"
#include "c_draw_object.h"
#include "c_draw_texture_cache.h"
#include <GLFW\glfw3.h>
#include <iostream>

namespace DRAW {

	Batcher * Batcher::_instance;

	void Batcher::Batch( Polytope * polytope ) {

		s_batch * batch = NULL;

		for( int i = 0; i < _batches.size( ); i++ ) {
			if( _batches[i]->texture == polytope->TextureIndex( ) ) {
				batch = _batches[i];
				break;
			}
		}

		if( !batch ) {
			batch = CreateBatch( polytope->TextureIndex( ) );
		}

		batch->object->AddData( polytope->GetData( ) );

	}

	s_batch * Batcher::CreateBatch( uint textureIndex ) {
		s_batch * batch = new s_batch( );
		batch->object = new Object( );
		batch->object->AllocateMemory( 1024, 2048 );
		batch->texture = textureIndex;
		_batches.push_back( batch );
		return batch;
	}

	void Batcher::DrawAll( ) {
		for( int i = 0; i < _batches.size( ); i++ ) {
			s_batch * batch = _batches[i];
			batch->object->BuildVAO( );
			glBindTexture( GL_TEXTURE_2D, batch->texture );
			batch->object->Draw( );
			batch->object->~Object( );
		}
		_batches.clear( );
	}

	Batcher * Batcher::Instance( ) {
		if( !_instance ) _instance = new Batcher( );
		return _instance;
	}

}