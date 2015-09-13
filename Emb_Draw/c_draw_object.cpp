
#include "c_draw_object.h"
#include <GL\glew.h>
#include <memory>
#include "c_draw_shader.h"
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include "c_draw_texture_cache.h"

namespace DRAW {

	Object::Object( ) {

	}

	void Object::AddData( s_polyData * data ) {

		for( int i = 0; i < data->indexCount; i++ ) {
			data->indices[i] += _n_verts;
		}

		memcpy( &_points[_n_verts * VERT_POS_SIZE], data->point, data->vertCount * VERT_POS_SIZE * sizeof( float ) );
		memcpy( &_cols[_n_verts * VERT_COL_SIZE], data->color, data->vertCount * VERT_COL_SIZE * sizeof( float ) );
		memcpy( &_tex[_n_verts * VERT_TEX_SIZE], data->tex, data->vertCount * VERT_TEX_SIZE * sizeof( float ) );
		memcpy( &_elements[_n_indices], data->indices, data->indexCount * sizeof( uint ) );

		_n_verts += data->vertCount;
		_n_indices += data->indexCount;

		delete( data );

	}

	void Object::BuildVAO( ) {

		glGenBuffers( 1, &_pointVBO );
		glBindBuffer( GL_ARRAY_BUFFER, _pointVBO );
		glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * _n_verts * VERT_POS_SIZE, _points, GL_STREAM_DRAW );

		glGenBuffers( 1, &_colVBO );
		glBindBuffer( GL_ARRAY_BUFFER, _colVBO );
		glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * _n_verts * VERT_COL_SIZE, _cols, GL_STREAM_DRAW );

		glGenBuffers( 1, &_texVBO );
		glBindBuffer( GL_ARRAY_BUFFER, _texVBO );
		glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * _n_verts * VERT_TEX_SIZE, _tex, GL_STREAM_DRAW );

		glGenVertexArrays( 1, &_vaoIndex );
		glBindVertexArray( _vaoIndex );

		glBindBuffer( GL_ARRAY_BUFFER, _pointVBO );
		glVertexAttribPointer( 0, VERT_POS_SIZE, GL_FLOAT, GL_FALSE, 0, NULL );

		glBindBuffer( GL_ARRAY_BUFFER, _colVBO );
		glVertexAttribPointer( 1, VERT_COL_SIZE, GL_FLOAT, GL_FALSE, 0, NULL );

		glBindBuffer( GL_ARRAY_BUFFER, _texVBO );
		glVertexAttribPointer( 2, VERT_TEX_SIZE, GL_FLOAT, GL_FALSE, 0, NULL );

		glEnableVertexAttribArray( 0 );
		glEnableVertexAttribArray( 1 );
		glEnableVertexAttribArray( 2 );

	}

	void Object::AllocateMemory( uint n_verts, uint n_indices ) {
		_points = (float*) calloc( sizeof( float ) * VERT_POS_SIZE, n_verts );
		_cols = (float*) calloc( sizeof( float ) * VERT_COL_SIZE, n_verts );
		_tex = (float*) calloc( sizeof( float ) * VERT_TEX_SIZE, n_verts );
		_elements = (uint*) calloc( sizeof( uint ), n_indices );
	}

	void Object::Draw( ) {
		glBindVertexArray( _vaoIndex );
		glDrawElements( GL_TRIANGLES, _n_indices, GL_UNSIGNED_INT, _elements );
	}

	void * Object::GetMappedBuffer( ) {
		glBindBuffer( GL_ARRAY_BUFFER, _pointVBO );
		return glMapBuffer( GL_ARRAY_BUFFER, GL_READ_WRITE );
	}

	Object::~Object( ) {

		//free( _elements );
		//free( _points );
		//free( _tex );
		//free( &_cols );

		glDeleteVertexArrays( 1, &_vaoIndex );
		glDeleteBuffers( 1, &_pointVBO );
		glDeleteBuffers( 1, &_colVBO );
		glDeleteBuffers( 1, &_texVBO );
		glDeleteBuffers( 1, &_elementVBO );

	}

}