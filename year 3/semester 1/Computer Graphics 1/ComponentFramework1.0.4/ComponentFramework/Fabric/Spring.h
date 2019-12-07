#ifndef SPRING_H
#define SPRING_H

struct Particle;
struct Spring {
	Particle* connectedParticles[2];
	float strength;
	Spring() {}
	Spring(float strength, Particle* p1, Particle* p2) {
		this->strength = strength;
		connectedParticles[0] = p1;
		connectedParticles[1] = p2;
	}

};
#endif // !SPRING_H
