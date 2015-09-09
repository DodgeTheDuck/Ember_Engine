
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# C_CORE_STATE_CONTROLLER.H
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# Auther: Duncan Edwards

#pragma once

#include "c_core_defs.h"
#include <stack>

namespace CORE {

	class IState;

	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# CORE::StateController
	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# Implementation: Singleton
	//~# Usage: Bridges the gap between the Engine and the Application, Push your derived IState on to this controller
	//~#	-and the Engine will do all the work

	class EMB_CORE_API StateController {

		public:
		//~# Call the Tick function of the stack top
		void Tick( );
		//~# Call the Draw function of the stack top
		void Draw( );
		//~# Add new State on to top of stack
		void Push( IState * state );
		//~# Remove the top of stack
		void Pop( );
		//~# Singleton Instance
		static StateController * Instance( );

		private:
		StateController( ) { };
		~StateController( ) { };
		void operator=( const StateController& );

		static StateController * _instance;

		std::stack<IState*> _states;



	};

}
