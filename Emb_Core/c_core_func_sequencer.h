
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# C_CORE_FUNC_SEQUENCER.H
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# Auther: Duncan Edwards

#pragma once

#include "c_core_defs.h"
#include <functional>
#include <chrono>
#include <iostream>
#include <string>

using namespace std::chrono;

namespace CORE {

	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# CORE::FuncSequencer
	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# Implementation: Class
	//~# 

	template< class T >
	class EMB_CORE_API FuncSequencer {

		public:

		enum e_fireType {
			FIRE_REPEAT,
			FIRE_ONCE
		};

		FuncSequencer( ) {
			_timeLastFrame = high_resolution_clock::now( );
			_secondTimer.zero( );
		}

		void SetFunction( const T& ref, void(T::*fp)(), long double callsPerSecond, e_fireType fireType = FIRE_REPEAT ) {
			_func = std::bind( fp, ref );
			_fireType = fireType;
			_cps = callsPerSecond;
			_hasFired = false;
		}

		void SetCallsPerSecond( long double cps ) {
			_cps = cps;
		}

		void Tick( ) {

			if( !( _fireType == FIRE_ONCE && _hasFired ) ) {
				if( _cps > 0.0 ) {

					time_point<high_resolution_clock> timeNow = high_resolution_clock::now( );

					auto delta = timeNow.time_since_epoch( ) - _timeLastFrame.time_since_epoch( );

					_secondTimer += delta;
					_counter += delta;

					long double countLimit = 1.0 / _cps;

					long double time = _counter.count( );

					if( time + _excess >= countLimit ) {
						_excess = time - countLimit;
						if( _excess < 0 ) _excess = 0;
						_func( );
						_counter = duration<long double>::zero( );
						_hasFired = true;
						_callCount++;
					}

					_timeLastFrame = timeNow;

					if( _secondTimer.count( ) >= 1.0 ) {
						_callsLastSecond = _callCount;
						_secondTimer = duration<long double>::zero( );
						_callCount = 0;
						std::cout << this << " Rate: " << _callsLastSecond << std::endl;
					}

				}
			}

		}

		void Reset( ) { 
			_counter = duration<long double>::zero( );
			_hasFired = false;
		}

		private:

		std::function<void()> _func;
		
		long double		_cps = 0.0;
		long double		_excess = 0.0;

		unsigned int	_callCount = 0;
		unsigned int	_callsLastSecond = 0;



		e_fireType		_fireType;
		bool			_hasFired;

		time_point<high_resolution_clock>				_timeLastFrame;
		duration<long double>							_counter = duration<long double>::zero( );
		duration<long double>							_secondTimer = duration<long double>::zero( );

	};

}