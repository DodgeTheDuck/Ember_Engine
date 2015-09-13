
#include "c_draw_input.h"
#include "c_draw_window.h"
#include <GLFW\glfw3.h>

namespace DRAW {

	namespace INPUT {

		bool Controls::left = false;
		bool Controls::right = false;
		bool Controls::forward = false;
		bool Controls::backward = false;
		bool Controls::fire = false;
		bool Controls::restart = false;
		long double Controls::mx = 0;
		long double Controls::my = 0;
		Window * Controls::context = NULL;

		void move( GLFWwindow * window, int key, int scancode, int action, int mods ) {

			if( key == GLFW_KEY_A && action == GLFW_PRESS ) Controls::left = true;
			if( key == GLFW_KEY_A && action == GLFW_RELEASE ) Controls::left = false;

			if( key == GLFW_KEY_D && action == GLFW_PRESS ) Controls::right = true;
			if( key == GLFW_KEY_D && action == GLFW_RELEASE ) Controls::right = false;

			if( key == GLFW_KEY_W && action == GLFW_PRESS ) Controls::forward = true;
			if( key == GLFW_KEY_W && action == GLFW_RELEASE ) Controls::forward = false;

			if( key == GLFW_KEY_S && action == GLFW_PRESS ) Controls::backward = true;
			if( key == GLFW_KEY_S && action == GLFW_RELEASE ) Controls::backward = false;

			if( key == GLFW_KEY_R && action == GLFW_PRESS ) Controls::restart = true;
			if( key == GLFW_KEY_R && action == GLFW_RELEASE ) Controls::restart = false;

		}

		void cursor( GLFWwindow * window, double xpos, double ypos ) {

			Controls::mx = xpos;
			Controls::my = ypos;

		}

		void mouse( GLFWwindow * window, int button, int action, int mods ) {

			if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS ) Controls::fire = true;
			if( button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE ) Controls::fire = false;

		}

		void Init( DRAW::Window * window ) {

			glfwSetKeyCallback( window->GetHandle( ), move );
			glfwSetCursorPosCallback( window->GetHandle( ), cursor );
			glfwSetMouseButtonCallback( window->GetHandle( ), mouse );
			Controls::context = window;

		}

		void CenterMouse( ) {
			TYPE::size_i size = Controls::context->GetSize( );
			SetMousePosition( { (real) size.w / 2,(real) size.h / 2 } );
		}

		void SetMousePosition( TYPE::point_f2 pos ) {
			glfwSetCursorPos( Controls::context->GetHandle( ), pos.x, pos.y );
		}

	}

}