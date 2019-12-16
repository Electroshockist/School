#ifndef SPRING_H
#define SPRING_H

#include "../VMath.h"

struct Particle;
struct Spring {
	Particle* connectedParticles[2];
	float strength;

	float distance, restDistance;

	Spring() {}
	Spring(float strength, Particle* p1, Particle* p2);

};
#endif // !SPRING_H
