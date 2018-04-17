#include "Scene.h"

void Scene::Physics(Body** bodies) {
	//figure out how to dynamically set this
	Vec3 Force[3];
	for (int i = 1; i < 3; i++) {
		//temporarily holds the current star's position relative to the planet 
		tempPos.x = bodies[i]->pos.x - bodies[0]->pos.x;
		tempPos.y = bodies[i]->pos.y - bodies[0]->pos.y;

		//gets the square of the hypotenuse
		csquared = pow(tempPos.x, 2) + pow(tempPos.y, 2);

		//gets the angle opposite the planet
		theta = atan2(tempPos.y, tempPos.x);

		//finds the direct force of gravity acting on the planet
		normalForce = (bodies[i]->mass * bodies[0]->mass) / csquared;

		//seperates the direct force into their x and y components
		Force[i].x = cos(theta) * normalForce;
		Force[i].y = sin(theta) * normalForce;
	}
	//adds the forces from star 1 and star 2
	Force[0] = Force[1] + Force[2];

	//applies the forces to the planet
	bodies[0]->ApplyForce(Force[0]);

}