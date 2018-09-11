#include "World.h"



World::World() {
}


World::World(Vector2D gravityAccel_, Vector2D windForce_) {
	gravityAccel = gravityAccel_;
	windForce = windForce_;
};

void World::addTwoBodies(Body* body1, Body* body2) {
	//works now, might cause problems later
	bodies[0] = body1;
	bodies[1] = body2;
}
void World::Update(float timestep) {

}

World::~World() {
}
