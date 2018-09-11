#ifndef Body_h
#define Body_h
#include "Vector2D.h"


class Body
{
public:
	double mass;
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	Vector2D prevVel;

	//Constructors
	Body();
	Body(double newMass);
	Body(double newMass, Vector2D& newPosition, Vector2D& newVelocity, Vector2D& newAcceleration);

	//Methods
	void Update(double timeStep);
	void ApplyForce(Vector2D& force);

};
#endif
