#pragma once

#include "c_math_defs.h"
#include <c_type_general.h>

namespace MATH {

	class EMB_MATH_API Vec3 {

		public:
		Vec3( real x = 0, real y = 0, real z = 0 ) :
			x( x ),
			y( y ),
			z( z ) { }

		real x, y, z;

		Vec3 Invert( ) { return Vec3( -x, -y, -z ); };

		void operator	+= ( Vec3 other ) { x += other.x; y += other.y; z += other.z; };
		void operator	-= ( Vec3 other ) { x -= other.x; y -= other.y; z -= other.z; };
		void operator	*= ( Vec3 other ) { x *= other.x; y *= other.y; z *= other.z; };
		void operator	*= ( real other ) { x *= other; y *= other; z *= other; };
		Vec3 operator - ( Vec3 other ) { return Vec3( x - other.x, y - other.y, z - other.z ); };
		Vec3 operator + ( Vec3 other ) { return Vec3( x + other.x, y + other.y, z + other.z ); };
		Vec3 operator * ( Vec3 other ) { return Vec3( x*other.x, y*other.y, z*other.z ); };
		Vec3 operator * ( real other ) { return Vec3( x*other, y*other, z*other ); };

	};

}
