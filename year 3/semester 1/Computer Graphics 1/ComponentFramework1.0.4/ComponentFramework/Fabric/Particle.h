#ifndef PARTICLE_H
#define PARTICLE_H

#include "Spring.h"
#include "../Vector.h"

#include <vector>

using namespace MATH;
struct Particle {
	Vec3* position;
	Vec3 velocity, acceleration;
	float mass;
	bool isLocked = false;

	std::vector<Spring> attachedSprings;

	Particle() {}

	Particle(Vec3& position, float mass);

	void update(const float deltaTime);

	inline void addForce(const Vec3 force) {
		acceleration = force / mass;
	}

	void connectTo(Particle* particle);
};

#endif // !PARTICLE_H

