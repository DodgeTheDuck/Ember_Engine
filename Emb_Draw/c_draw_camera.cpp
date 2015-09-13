
#include "c_draw_camera.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

namespace DRAW {

	glm::mat4 _view;

	Camera::Camera( TYPE::point_f3 position ) {
		_position = position;
	}

	void Camera::Move( float dx, float dy, float dz ) {
		_view = glm::translate( _view, glm::vec3( dx, dy, dx ) );
	}

	float * Camera::GetViewMatrix( ) {

		return glm::value_ptr( _view );

	}

	TYPE::point_f3 Camera::GetPosition( ) {
		return _position;
	}

}