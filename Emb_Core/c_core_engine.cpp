
#include "c_core_engine.h"
#include "c_core_state_controller.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

time_point<high_resolution_clock> _timeLastFrame;
duration< long double > _tickCounter = duration<long double>::zero( );
duration< long double > _drawCounter = duration<long double>::zero( );
duration< long double > _secondCounter = duration<long double>::zero( );

long double _tickExcess = 0;
long double _drawExcess = 0;

long double _tickRate = 1.l / 128.l;
long double _drawRate = 1.l / 128.l;

long double _tickHelper = 0;

unsigned int _nTicks = 0;
unsigned int _nDraws = 0;
unsigned int _nLoops = 0;

namespace CORE {

	Engine * Engine::_instance;

	void Engine::Init( ) {

		_running = true;

	}

	void Engine::Run( ) {
		while( _running ) {

			_nLoops++;

			time_point<high_resolution_clock> now = high_resolution_clock::now( );

			auto delta = now.time_since_epoch( ) - _timeLastFrame.time_since_epoch( );

			_tickCounter += delta;
			_drawCounter += delta;
			_secondCounter += delta;

			if( _tickCounter.count( ) + _tickExcess >= _tickRate ) {
				_tickExcess = _tickCounter.count( ) - _tickRate;
				Tick( );
				_nTicks++;
				_tickCounter = duration<long double>::zero( );
			}

			if( _drawCounter.count( ) + _drawExcess >= _drawRate ) {
				_drawExcess = _drawCounter.count( ) - _drawRate;
				Draw( );
				_nDraws++;
				_drawCounter = duration<long double>::zero( );
			}

			if( _secondCounter.count( ) >= 1.0 ) {
				std::cout << "Tick Rate: " << _nTicks << "\t\tDraw Rate: " << _nDraws << "\t\tCore Loops:" << _nLoops << std::endl;
				_secondCounter = duration<long double>::zero( );
				_nDraws = 0;
				_nTicks = 0;
				_nLoops = 0;
			}

			_timeLastFrame = now;

		}
	}

	void Engine::Tick( ) {
		StateController::Instance( )->Tick( );
	}

	void Engine::Draw( ) {
		StateController::Instance( )->Draw( );
	}

	void Engine::Shutdown( ) {

		_running = false;

	}

	Engine * Engine::Instance( ) {
		if( !_instance ) _instance = new Engine( );
		return _instance;
	}

}