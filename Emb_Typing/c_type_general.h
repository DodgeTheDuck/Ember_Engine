
#pragma once

#include "c_type_defs.h"
#include <string>

typedef unsigned int uint;
typedef double real;

namespace TYPE {

	typedef std::string string;

	struct EMB_TYPE_API point_f2 {
		real x;
		real y;
	};

	struct EMB_TYPE_API point_f3 {
		real x;
		real y;
		real z;
	};

	struct EMB_TYPE_API size_i {
		int w;
		int h;
	};

	struct EMB_TYPE_API color_f4 {
		real r;
		real g;
		real b;
		real a;
	};

	struct EMB_TYPE_API rect_f {
		real left;
		real top;
		real right;
		real bottom;
	};

}
