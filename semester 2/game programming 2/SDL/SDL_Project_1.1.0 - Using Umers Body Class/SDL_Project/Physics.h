#include "Vector.h"
#include "Body.h"

class Physics
{
private:
	int numbodies;
	Body* bodies;
	Vec3* Force;
	class Vec3 tempPos;
	double csquared;
	double theta;
	double normalForce;

public:
	Physics(int _numbodies, Body* _bodies, Vec3* _Force);
	void Run();
};

