#ifndef SPRING_H
#define SPRING_H

#include "../VMath.h"

struct Particle;
struct Spring {
	float strength;

	Spring() {}
	Spring(float strength, Particle* p1, Particle* p2);

	MATH::Vec3 getDistance();

	bool doesParticleExist(const Particle* particle);

private:
	Particle* connectedParticles[2];
	MATH::Vec3 restPos;
};
#endif // !SPRING_H
