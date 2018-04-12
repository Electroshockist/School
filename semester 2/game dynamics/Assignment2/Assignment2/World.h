#ifndef WORLD_H
#define WORLD_H
#include "Body.h"
class World
{
public:
	Body *bodies[2];
	float elapsedTime;

	Vector2D gravityAccel;
	Vector2D windForce;
	Vector2D appliedForce;

	World();
	World(Vector2D gravityAccel_, Vector2D windForce_);

	void addTwoBodies(Body* body1, Body* body2);
	void Update(float timestep);

	~World();
};
#endif