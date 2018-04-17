#include "Collider.h"
#include "Body.h"
#include "VMath.h"

using namespace MATH;

//find radius
bool Collided(const Body& b1, const Body& b2) {
	float d = VMath::distance(b1.pos, b2.pos);
	return true;
}

void Collider::HandleCollision(Body& b1, Body& b2) {
	float epsilon = 1.0f;
	Vec3 Normal = VMath::normalize(b2.pos - b1.pos);

	float InitialVelocity1 = VMath::dot(b1.vel, Normal);
	float InitialVelocity2 = VMath::dot(b2.vel, Normal);

	float v1pPrime = (b1.mass - 1.0f * b2.mass) * InitialVelocity1 + (1 + epsilon) * b2.mass * InitialVelocity2 / (b1.mass + b2.mass);
	float v2pPrime = (b2.mass - 1.0f * b1.mass) * InitialVelocity2 + (1 + epsilon) * b1.mass * InitialVelocity1 / (b1.mass + b2.mass);

	Vec3 v1pr = (v1pPrime - InitialVelocity1) * Normal;
	Vec3 v2pr = (v2pPrime - InitialVelocity2) * Normal;
}
