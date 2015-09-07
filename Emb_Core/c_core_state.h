
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# C_CORE_STATE.H
//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
//~# Auther: Duncan Edwards

#pragma once

#include "c_core_defs.h"

namespace CORE {

	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# CORE::IState
	//~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~
	//~# Implementation: Interface
	//~# Usage: Derive from this and add to CORE::StateController to essentially plug your application in to the Engine.
	//~# Notes: My current implementation of a State system should allow you to seperate Menu code from Game code
	//~#			-but is limited slightly in that no drawing will happen to any state other than the stack top. My
	//~#			-current plan is to remove the stack limitation, use a vector and add the ability to 'Pause/Unpause'
	//~#			-a state at will. This will mean a Pause menu State could be added that allows the Game State to be 
	//~#			-in the background. I'm still unsure though if the absolute determinate 'One State doing anything at a time'
	//~#			-is better.

	class EMB_CORE_API IState {

		public:

		IState( ) { };

		//~# Initialise anything you need to initiate using this function
		virtual void Init( ) = 0;
		//~# Call this AFTER Initialisaion, otherwise Opengl won't be initialised and your Textures will cause big scary looking errors.
		virtual void LoadContent( ) = 0;
		//~# When plugged in to the State Controller, both Tick( ) and Draw( ) will be called for you at x Tickrate and y Drawrate.
		virtual void Tick( ) = 0;
		virtual void Draw( ) = 0;

	};

}