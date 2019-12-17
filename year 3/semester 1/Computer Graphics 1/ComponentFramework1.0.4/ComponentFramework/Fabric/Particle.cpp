#include "Particle.h"

using namespace std;
using namespace MATH;

Particle::Particle(Vec3 * position, float mass) : velocity(Vec3()) {
	this->position = position;
	this->mass = mass;
}

void Particle::update(const float deltaTime) {

	for(Spring* spring : attachedSprings) {
		if(!isLocked) {
			acceleration = (spring->strength * spring->getDistance()) / mass;

			*position += velocity * deltaTime + (acceleration * deltaTime * deltaTime) / 2 - dampening * velocity;
			velocity += acceleration * deltaTime;
		}
	}
}

void Particle::connectTo(Particle * particle) {
	//check if the particle has already been connected
	for(Spring* spring : attachedSprings) {
		if(spring->doesParticleExist(*particle)) {
			std::cout << "These particles have already been connected" << std::endl;
			return;
		}
	}
	Spring* spring = new Spring(1, this, particle);
}


