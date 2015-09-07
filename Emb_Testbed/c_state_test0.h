
#pragma once

#include <c_core_state.h>

class Test0 final : public CORE::IState {

	public:
	Test0( );
	~Test0( );

	virtual void LoadContent( );
	virtual void Init( );
	virtual void Tick( );
	virtual void Draw( );

};