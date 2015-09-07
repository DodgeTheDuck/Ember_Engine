
#pragma once

#include "c_type_defs.h"
#include <string>

typedef unsigned int uint;

namespace TYPE {

	typedef std::string string;

	struct EMB_TYPE_API point_f2 {
		float x;
		float y;
	};

	struct EMB_TYPE_API point_f3 {
		float x;
		float y;
		float z;
	};

	struct EMB_TYPE_API size_i {
		int w;
		int h;
	};

	struct EMB_TYPE_API color_f4 {
		float r;
		float g;
		float b;
		float a;
	};

	struct EMB_TYPE_API rect_f {
		float left;
		float top;
		float right;
		float bottom;
	};

}
