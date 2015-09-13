
#include "c_draw_camera.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx\quaternion.hpp>
#include "c_draw_input.h"
#include "c_draw_window.h"
#include <iostream>

namespace DRAW {

	glm::mat4 _view;
	glm::vec3 _rotation;

	Camera::Camera( TYPE::point_f3 position ) {
		_position = position;
	}

	void Camera::Move( real dx, real dy, real dz ) {
		_position += { dx, dy, dz };
	}

	void Camera::MoveLocal( real angle, real speed ) {
		_position.x += cos( ( ( angle + 90 ) * 3.14 / 180.0 ) + _rotation.y ) * speed;
		_position.z += sin( ( ( angle + 90 ) * 3.14 / 180.0 ) + _rotation.y ) * speed;
	}

	void Camera::Rotate( real angle, TYPE::point_f3 axis ) {
		_rotation.x += angle * axis.x;
		_rotation.y += angle * axis.y;
		_rotation.z += angle * axis.z;
	}

	void Camera::MouseLook( ) {

		TYPE::size_i windowSize = INPUT::Controls::context->GetSize( );

		real deltax = ( (real) windowSize.w / 2 ) - INPUT::Controls::mx;
		real deltay = ( (real) windowSize.h / 2 ) - INPUT::Controls::my;

		Rotate( deltax / 1000.0, { 0, -1, 0 } );
		Rotate( deltay / 1000.0, { -1, 0, 0 } );

		INPUT::CenterMouse( );

	}

	TYPE::point_f3 Camera::GetPosition( ) {
		return _position;
	}

	TYPE::point_f3 Camera::GetRotation( ) {
		return{ _rotation.x, _rotation.y, _rotation.z };
	}

}