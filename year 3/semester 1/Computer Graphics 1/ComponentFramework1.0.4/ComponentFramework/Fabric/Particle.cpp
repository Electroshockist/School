#include "Particle.h"

Particle::Particle(Vec3 & position, float mass) {
	this->position = &position;
	this->mass = mass;
}

void Particle::update(const float deltaTime) {
	*position += velocity * deltaTime + (acceleration * deltaTime * deltaTime) / 2;
	velocity += acceleration * deltaTime;
}

void Particle::connectTo(Particle * particle) {
	for(Spring s : particle->attachedSprings) {
		for(Particle* p : s.connectedParticles) {
			if(p == particle) {
				std::cout << "These particles have already been connected" << std::endl;
				return;
			}
		}
	}
	Spring spring = Spring(1, this, particle);
	attachedSprings.push_back(spring);
	particle->attachedSprings.push_back(spring);
}


