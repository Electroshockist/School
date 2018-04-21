#include "Collider.h"
#include "Body.h"
#include "VMath.h"

using namespace MATH;

//ask scott how to convert Body* array to Body
bool Collider::Collided(const Body& b1, const Body& b2) {
	float d = VMath::distance(b1.pos, b2.pos);
	if (d < b1.radius + b2.radius) return true;
	else return false;
}

void Collider::HandleCollision(Body& b1, Body& b2) {
	float epsilon = 1.0f;
	Vec3 Normal = VMath::normalize(b2.pos - b1.pos);
	printf("%f, %f\n", Normal.x, Normal.y);

	float InitialVelocity1 = VMath::dot(b1.vel, Normal);
	float InitialVelocity2 = VMath::dot(b2.vel, Normal);

	float FinalVelocity1 = (b1.mass - epsilon * b2.mass) * InitialVelocity1 + (1 + epsilon) * b2.mass * InitialVelocity2 / (b1.mass + b2.mass);
	float FinalVelocity2 = (b2.mass - epsilon * b1.mass) * InitialVelocity2 + (1 + epsilon) * b1.mass * InitialVelocity1 / (b1.mass + b2.mass);

	Vec3 v1pr = (FinalVelocity1 - InitialVelocity1) * Normal;
	Vec3 v2pr = (FinalVelocity2 - InitialVelocity2) * Normal;
}
