
#include "c_draw_setup.h"
#include "c_draw_window.h"
#define GLFW_INCLUDE_GLU
#include <gl\glew.h>
#include <GLFW\glfw3.h>


namespace DRAW {

	void Setup::InitStart( ) {
		glfwInit( );
	}

	void Setup::SetVSync( bool value ) {
		if( value ) 
			glfwSwapInterval( 1 );
		else 
			glfwSwapInterval( 0 );
	}

	void Setup::SetRenderContext( Window * context ) {
		glfwMakeContextCurrent( context->GetHandle( ) );
	}

	void Setup::SetClearColor( TYPE::color_f4 color ) {
		glClearColor( color.r, color.g, color.b, color.a );
	}

	void Setup::InitEnd( ) {

		glewExperimental = GL_TRUE;
		glewInit( );

	}

}