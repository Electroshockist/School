#include "Particle.h"

Spring::Spring(float strength, Particle * p1, Particle * p2) {
	this->strength = strength;
	connectedParticles[0] = p1;
	connectedParticles[1] = p2;

	distance = restDistance = MATH::VMath::distance(*p1->position, *p2->position);
}
