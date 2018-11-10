
#include "Body.h"
#include "VMath.h"

using namespace MATH;

class Collider
{
private:
	static Vec3 Max(const Body& body, Vec3 D);
	static Vec3 Min(const Body& body, Vec3 D);
public:
	static Vec3 getNorm(Vec3 N1, Vec3 N2, Vec3 orginLine);
	static bool Collided(const Body& b1, const Body& b2);
	static void HandleCollision(Body& b1, Body& b2);
};