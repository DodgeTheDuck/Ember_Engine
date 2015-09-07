
#pragma once

#include "c_core_defs.h"
#include <stack>

namespace CORE {

	class IState;

	class EMB_CORE_API StateController {

		public:
		void Tick( );
		void Draw( );
		void Push( IState * state );
		void Pop( );
		static StateController * Instance( );

		private:
		StateController( ) { };
		~StateController( ) { };
		void operator=( const StateController& );

		static StateController * _instance;

		std::stack<IState*> _states;



	};

}
