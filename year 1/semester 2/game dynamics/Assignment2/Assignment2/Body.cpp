#include "Body.h"
Body::Body() {

	mass = 0;
	position.SetZero();
	velocity.SetZero();
	acceleration.SetZero();
}
Body::Body(double newMass) {
	mass = newMass;
	position.SetZero();
	velocity.SetZero();
	acceleration.SetZero();
}

Body::Body(double newMass, Vector2D& newPostion, Vector2D& newVelocity, Vector2D& newAcceleration) {
	//setup
	mass = newMass;
	position = newPostion;
	velocity = newVelocity;
	acceleration = newAcceleration;
}

void Body::Update(double timeStep) {
	prevVel.x = velocity.x;
	prevVel.y = velocity.y;

	//sets x velocity
	velocity.x = prevVel.x + acceleration.x * timeStep;
	//sets y velocity
	velocity.y = prevVel.y + acceleration.y * timeStep;

	//sets x displacement
	position.x += (velocity.x + prevVel.x) / 2 * timeStep;
	position.y += (velocity.y + prevVel.y) / 2 * timeStep;

	acceleration.SetZero();
}

void Body::ApplyForce(Vector2D& force) {
	acceleration.x += force.x / mass;
	acceleration.y += force.y / mass;
}

