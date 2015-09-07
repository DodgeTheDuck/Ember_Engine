
#include "c_draw_shader.h"
#include <gl\glew.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace DRAW {

	Shader::Shader( const char * fragment, const char * vertex ) {

		std::fstream frag_file;
		std::fstream vert_file;

		frag_file.open( fragment );
		vert_file.open( vertex );

		std::string line;

		std::string frag_src;
		std::string vert_src;

		if( frag_file.is_open( ) ) {
			while( std::getline( frag_file, line ) ) {
				frag_src += line + '\n';
			};
			frag_src += '\0';
			frag_file.close( );
		} else {
			std::cout << "Failed to open fragment src" << std::endl;
		}

		if( vert_file.is_open( ) ) {
			while( std::getline( vert_file, line ) ) {
				vert_src += line + '\n';
			};
			vert_src += '\0';
			vert_file.close( );
		} else {
			std::cout << "Failed to open vertex src" << std::endl;
		}

		int fs = frag_src.size( );
		int vs = vert_src.size( );
		const char * f = frag_src.c_str( );
		const char * v = vert_src.c_str( );

		_fragIndex = glCreateShader( GL_FRAGMENT_SHADER );
		glShaderSource( _fragIndex, 1, &f, NULL );
		glCompileShader( _fragIndex );

		_vertIndex = glCreateShader( GL_VERTEX_SHADER );
		glShaderSource( _vertIndex, 1, &v, NULL );
		glCompileShader( _vertIndex );

		_programIndex = glCreateProgram( );
		glAttachShader( _programIndex, _fragIndex );
		glAttachShader( _programIndex, _vertIndex );

		glBindAttribLocation( _programIndex, 0, "vertex_position" );
		glBindAttribLocation( _programIndex, 1, "vertex_colour" );

		glLinkProgram( _programIndex );

		int isLinked = 0;
		glGetProgramiv( _programIndex, GL_LINK_STATUS, &isLinked );

		if( !isLinked ) {
			GLint maxLength = 0;
			glGetProgramiv( _programIndex, GL_INFO_LOG_LENGTH, &maxLength );
			std::vector<GLchar> infoLog( maxLength );
			glGetProgramInfoLog( _programIndex, maxLength, &maxLength, &infoLog[0] );
			for( int i = 0; i < infoLog.size( ); i++ ) {
				std::cout << infoLog[i];
			}
		}

		glDeleteShader( _fragIndex );
		glDeleteShader( _vertIndex );

		glDetachShader( _programIndex, _fragIndex );
		glDetachShader( _programIndex, _vertIndex );


	}

	void Shader::UniformMatrix4( const char * name, const float * data ) {
		GLint loc = glGetUniformLocation( _programIndex, name );
		glUniformMatrix4fv( loc, 1, 1, data);
	}

	void Shader::UseProgram( ) {
		glUseProgram( _programIndex );
	}

}