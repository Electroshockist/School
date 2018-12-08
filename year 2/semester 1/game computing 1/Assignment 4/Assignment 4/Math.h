#ifndef MATH_H
#define MATH_H

#include <math.h>

namespace AngleMath{
	#ifndef VERY_SMALL
	#define VERY_SMALL 1.0e-7f
	#endif

	#ifndef PI
	#define PI 3.14159265358979323846f
	#endif

	#ifndef DEGREES_TO_RADIANS
	#define DEGREES_TO_RADIANS (PI / 180.0f)
	#endif

	struct Math {
		//get absolute cos value and check if it's too small for a float to hold correctly
		inline static float checkCos(float angle) {
			if (abs(cos(angle)) > VERY_SMALL) return cos(angle);
			else return 0;
		}

		//get absolute sin value and check if it's too small for a float to hold correctly
		inline static float checkSin(float angle) {
			if (abs(sin(angle)) > VERY_SMALL) return sin(angle);
			else return 0;
		}
	};
}

#endif