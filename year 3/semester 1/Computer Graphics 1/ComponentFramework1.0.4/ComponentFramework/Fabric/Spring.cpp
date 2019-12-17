#include "Particle.h"

Spring::Spring(float strength, Particle * p1, Particle * p2) {
	this->strength = strength;
	connectedParticles[0] = p1;
	connectedParticles[1] = p2;

	p1->attachedSprings.push_back(this);
	p2->attachedSprings.push_back(this);

	restPos = *p1->position - *p2->position;
}

MATH::Vec3 Spring::getDistance() {
	return (*connectedParticles[0]->position - *connectedParticles[1]->position) - restPos;
}



bool Spring::doesParticleExist(const Particle& particle) {
	return *connectedParticles[0] == particle || *connectedParticles[1] == particle;
}
