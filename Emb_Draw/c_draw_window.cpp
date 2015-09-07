
#include "c_draw_window.h"
#include <GLFW\glfw3.h>

namespace DRAW {

	Window::Window( TYPE::size_i size ) {
		_instance = glfwCreateWindow( size.w, size.h, "Ember", NULL, NULL );
		_size = size;
	}

	void Window::HandleEvents( ) {
		if( _instance ) {
			glfwSwapBuffers( _instance );
			glfwPollEvents( );
		}
	}

	bool Window::ShouldClose( ) {
		return glfwWindowShouldClose( _instance );
	}

	TYPE::size_i Window::GetSize( ) {
		return _size;
	}

	GLFWwindow * Window::GetHandle( ) {
		return _instance;
	}

	Window::~Window( ) {

	}

}