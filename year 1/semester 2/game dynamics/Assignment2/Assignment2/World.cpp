#include "World.h"

World::World() {
}


World::World(Vector2D gravityAccel_, Vector2D windForce_) {
	gravityAccel = gravityAccel_;
	windForce = windForce_;
	elapsedTime = 0;
};

void World::addTwoBodies(Body* body1, Body* body2) {
	//works now, might cause problems later
	bodies[0] = body1;
	bodies[1] = body2;
}
void World::Update(float timestep) {
	
	bodies[0]->ApplyForce(windForce);
	bodies[1]->ApplyForce(windForce);

	if (elapsedTime <= 0.1) {
		appliedForce.Set(1000.0, 0.0);
	}
	else {
		appliedForce.SetZero();
	}
	bodies[0]->ApplyForce(appliedForce);
	bodies[1]->ApplyForce(appliedForce);

	bodies[0]->acceleration.y += gravityAccel.y;
	bodies[1]->acceleration.y += gravityAccel.y;

	bodies[0]->Update(timestep);
	bodies[1]->Update(timestep);
	
	elapsedTime += timestep;	
}

World::~World() {
}
