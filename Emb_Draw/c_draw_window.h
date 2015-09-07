
#pragma once

#include <c_type_general.h>
#include "c_draw_defs.h"

struct GLFWwindow;

namespace DRAW {

	class EMB_DRAW_API Window {

		public:
		Window( TYPE::size_i size );
		TYPE::size_i GetSize( );
		GLFWwindow * GetHandle( );
		void HandleEvents( );
		bool ShouldClose( );
		~Window( );
		private:
		TYPE::size_i _size;
		GLFWwindow * _instance;


	};

}