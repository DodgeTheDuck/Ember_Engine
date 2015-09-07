
#include "c_draw_camera.h"

namespace DRAW {

	Camera::Camera( TYPE::point_f3 position ) {
		_position = position;
	}

	void Camera::Move( float dx, float dy, float dz ) {
		_position.x += dx;
		_position.y += dy;
		_position.z += dz;
	}

	TYPE::point_f3 Camera::GetPosition( ) {
		return _position;
	}

}