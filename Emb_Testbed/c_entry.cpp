
#include <c_core_engine.h>
#include "c_state_test0.h"
#include "c_entry.h"
#include <c_core_setup.h>
#include <c_core_state_controller.h>
#include <c_draw_window.h>

int main( ) {

	CORE::Engine * engine = CORE::Engine::Instance( );
	engine->Init( );
	CORE::StateController::Instance( )->Push( new Test0( ) );
	engine->Run( );


}