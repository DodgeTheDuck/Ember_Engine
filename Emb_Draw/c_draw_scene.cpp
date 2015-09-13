

#include "c_draw_Scene.h"
#include <gl\glew.h>
#include "c_draw_shader.h"
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx\quaternion.hpp>
#include "c_draw_camera.h"
#include "c_draw_object.h"
#include "c_draw_batcher.h"
#include <iostream>

namespace DRAW {

	glm::mat4 _viewmodel;
	glm::mat4 _projection;

	Scene::Scene( TYPE::size_i viewSpace ) {
		_viewSpace = viewSpace;
		_sceneShader = new Shader( "frag.glsl", "vert.glsl" );
		_camera = new Camera( { 0.0, 0.0, -4 } );

		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	}

	void Scene::Tick( ) {

	}

	void Scene::Draw( ) {

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		if( _currentProj == DRAW_PROJ_PERSP ) {
			_camera->MouseLook( );
			TYPE::point_f3 camRot = _camera->GetRotation( );
			_viewmodel = glm::rotate( _viewmodel, (float) camRot.x, { 1.0, 0.0, 0.0 } );
			_viewmodel = glm::rotate( _viewmodel, (float) camRot.y, { 0.0, 1.0, 0.0 } );
			_viewmodel = glm::rotate( _viewmodel, (float) camRot.z, { 0.0, 0.0, 1.0 } );
		}

		TYPE::point_f3 camPos = _camera->GetPosition( );
		_viewmodel = glm::translate( _viewmodel, { camPos.x, camPos.y, camPos.z } );

		glm::mat4 MVP = _projection * _viewmodel;

		_sceneShader->UniformMatrix4( "MVP", glm::value_ptr( MVP ) );
		_sceneShader->UseProgram( );

		Batcher::Instance( )->DrawAll( );

	}

	void Scene::SetProjection( e_Projection projection ) {
		if( projection == DRAW_PROJ_ORTHO ) {
			_projection = glm::ortho( 0.0, (double) _viewSpace.w, (double) _viewSpace.h, 0.0, -1.0, 1.0 );
			glDisable( GL_DEPTH_TEST );
		} else if( projection == DRAW_PROJ_PERSP ) {
			_projection = glm::perspectiveFov( 45.0, (double)_viewSpace.w, (double) _viewSpace.h, 0.1, 1024.0 );
			glEnable( GL_DEPTH_TEST );
		}
		_currentProj = projection;
	}

	float * Scene::GetModelMatrix( ) {
		return glm::value_ptr( _viewmodel );
	}

	void Scene::LoadIdentity( ) {
		_viewmodel = glm::mat4( );
	}

	void Scene::Translate( TYPE::point_f3 translation ) {
		_viewmodel = glm::translate( _viewmodel, { translation.x, translation.y, translation.z } );
	}

	void Scene::Rotate( float degrees, TYPE::point_f3 axis ) {
		glm::quat rot = glm::angleAxis( degrees, glm::vec3( axis.x, axis.y, axis.z ) );
		_viewmodel *= glm::toMat4( rot );
	}

	void Scene::Clear( ) {
		_polys.clear( );
	}

	Camera * Scene::GetCamera( ) {
		return _camera;
	}

}