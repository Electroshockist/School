#include "Body.h"
Body::Body(){
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
	//sets jetski's x velocity
	velocity.x = prevVel.x + acceleration.x * timeStep;

	//sets jetski's x displacement
	position.x += (velocity.x + prevVel.x) / 2 * timeStep;
}

void Body::ApplyForce(Vector2D& force) {
	acceleration.x = force.x / mass;
}

