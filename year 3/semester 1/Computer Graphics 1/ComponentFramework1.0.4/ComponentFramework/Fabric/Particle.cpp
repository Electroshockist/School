#include "Particle.h"

using namespace std;
using namespace MATH;

Particle::Particle(Vec3 & position, float mass) : velocity(Vec3()) {
	this->position = &position;
	this->oldPos = position;
	this->mass = mass;
}

void Particle::update(const float deltaTime) {
	for(Spring* spring : attachedSprings) {
		for(Particle* particle : spring->connectedParticles) {
			if(particle != this) {
				Vec3 force = spring->strength * VMath::distance(*position, oldPos) * VMath::normalize(velocity) + Vec3(0, GRAVITY, 0);
				//force.print();
				addForce(force);
			}
		}
	}
	oldPos = *position;
	*position += velocity * deltaTime + (acceleration * deltaTime * deltaTime) / 2;
	velocity += acceleration * deltaTime;
}

void Particle::connectTo(Particle * particle) {
	//check if the particle has already been connected
	for(Spring* spring : attachedSprings) {
		for(Particle* p : spring->connectedParticles) {
			if(p == particle) {
				std::cout << "These particles have already been connected" << std::endl;
				return;
			}
		}
	}
	Spring* spring = new Spring(1, this, particle);
	attachedSprings.push_back(spring);
	particle->attachedSprings.push_back(spring);
}


