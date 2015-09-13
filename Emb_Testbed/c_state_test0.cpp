
#include "c_state_test0.h"
#include <iostream>
#include <c_draw_setup.h>
#include <c_core_engine.h>
#include <c_draw_window.h>
#include <c_draw_primitive.h>
#include <c_draw_scene.h>
#include <c_draw_texture_cache.h>
#include <c_draw_polytope.h>
#include <c_draw_batcher.h>
#include <c_draw_texture.h>
#include <c_draw_text.h>
#include <c_draw_input.h>

DRAW::Window * window;
DRAW::Scene * scene;

float x = 8;

Test0::Test0( ) {
	Init( );
	LoadContent( );
}

void Test0::LoadContent( ) {
	
	DRAW::TextureCache::Instance( )->Push( new DRAW::Texture( "sprites/font.png", { 6, 8 }, 1 ) );
	DRAW::TextureCache::Instance( )->Push( new DRAW::Texture( "sprites/grass.png" ) );

}

void Test0::Init( ) {

	DRAW::Setup::InitStart( );
	window = new DRAW::Window( { 1600, 900 } );
	DRAW::Setup::SetRenderContext( window );
	DRAW::Setup::SetVSync( false );
	DRAW::Setup::SetClearColor( { 0.5, 0.5, 0.5, 1.0 } );
	DRAW::Setup::InitEnd( );

	scene = new DRAW::Scene( window->GetSize( ) );
	scene->SetProjection( DRAW::Scene::DRAW_PROJ_PERSP );

}

void Test0::Tick( ) {
	scene->Tick( );
	window->HandleEvents( );
	if( window->ShouldClose( ) ) {
		CORE::Engine::Instance( )->Shutdown( );
	}
	if( DRAW::Controls::forward ) x -= 0.1;
}

void Test0::Draw( ) {

	scene->LoadIdentity( );
	scene->Translate( { x, 0, -10 } );
	scene->Rotate( x, { 0, 1, 0 } );

	DRAW::Batcher::Instance( )->Batch( new DRAW::PCube( 1, DRAW::TextureCache::Instance( )->Get( 1 ) ) );

	scene->Draw( );

}

Test0::~Test0( ) {

}