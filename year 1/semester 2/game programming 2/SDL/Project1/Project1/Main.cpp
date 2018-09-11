#include <stdio.h>

int main(int argc, char *argv[]) {
	float y = 10.0f;
	float v = 0.0f;
	float t = 1.0f / 60.0f;
	float a = -9.8f;
	for (int i = 0; i < 86 * 2; i++) {
		y += v * t + 0.5f * a * t * t;
		v += a * t;
		if (y <= 0.0f) {
			v = -v;
		}
		printf("pos: %f\n", y);
	}
	getchar();
}