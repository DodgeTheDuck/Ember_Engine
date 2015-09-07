
#include "c_core_state_controller.h"
#include "c_core_state.h"

namespace CORE {

	StateController * StateController::_instance;

	void StateController::Tick( ) {
		_states.top( )->Tick( );
	}

	void StateController::Draw( ) {
		_states.top( )->Draw( );

	}

	void StateController::Push( IState * state ) {
		_states.push( state );
	}

	void StateController::Pop( ) {
		_states.pop( );
	}

	StateController * StateController::Instance( ) {
		if( !_instance ) _instance = new StateController( );
		return _instance;
	}

}