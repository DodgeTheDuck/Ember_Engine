
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# C_CORE_ENGINE.H 
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# Auther: Duncan Edwards

#pragma once

#include "c_core_defs.h"

namespace CORE {

	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# CORE::Engine
	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# Implementation: Singleton
	//~# Usage: Create instance at application entry point, initiate and run.

	class EMB_CORE_API Engine {

		public:

		//~# Must be called before Run( ), Sounds important but does very little (for now)
		void Init( );
		//~# Core application loop, fires Tick( ) and Draw( ) at set intervals
		void Run( );
		//~# Calls the Tick( ) function of the top stacked CORE::State
		void Tick( );
		//~# Calls the DRAW( ) function of the top stacked CORE::State
		void Draw( );
		//~# Exits loop, will eventually make sure subsystems are deconstructed in a safe order
		void Shutdown( );

		//~# Return Singleton instance.
		static Engine * Instance( );

		private:

		//~# Private Constructor cause I don't want plebs to accidently make new Engines.
		Engine( ) { };
		//~# Disable Equality Operator because _instance will only ever equal _instance. More plebeian defense.
		void operator=( const Engine& );
		//~# The Singleton instance of Engine.
		static Engine * _instance;
		//~# Loop condition
		bool _running;

	};

}