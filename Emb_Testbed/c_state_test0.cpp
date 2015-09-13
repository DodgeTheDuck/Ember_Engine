
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
#include <c_draw_camera.h>

DRAW::Window * window;
DRAW::Scene * scene;

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

	if( DRAW::INPUT::Controls::forward ) scene->GetCamera( )->MoveLocal( 0, 0.05 );
	if( DRAW::INPUT::Controls::backward ) scene->GetCamera( )->MoveLocal( 180, 0.05 );
	if( DRAW::INPUT::Controls::left ) scene->GetCamera( )->MoveLocal( 270, 0.05 );
	if( DRAW::INPUT::Controls::right ) scene->GetCamera( )->MoveLocal( 90, 0.05 );

}

void Test0::Draw( ) {

	scene->SetProjection( DRAW::Scene::DRAW_PROJ_PERSP );
	scene->LoadIdentity( );

	for( int i = 0; i < 1; i++ ) {
		for( int j = 0; j < 1; j++ ) {
			for( int k = 0; k < 1; k++ ) {
				if( i == 0 || j == 0 || k == 0 || i == 3 || j == 3 || k == 3 ) DRAW::Batcher::Instance( )->Batch( new DRAW::PCube( { (real) i, (real) j, (real) k }, 0.5, DRAW::TextureCache::Instance( )->Get( 1 ) ) );
			}
		}
	}

	//scene->SetProjection( DRAW::Scene::DRAW_PROJ_ORTHO );
	//scene->LoadIdentity( );
	//DRAW::Text( "hello", 4.0 );

	scene->Draw( );

}

Test0::~Test0( ) {

}