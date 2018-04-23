#include "Collider.h"
#include "Body.h"
#include "VMath.h"

using namespace MATH;
float prevd = 0;

bool Collider::Collided(const Body& b1, const Body& b2) {
	float d = VMath::distance(b1.pos, b2.pos);
	printf("%f\n", d);
	if (d < b1.radius + b2.radius) return true;
	else return false;
}

void Collider::HandleCollision(Body& b1, Body& b2) {

	float d = VMath::distance(b1.pos, b2.pos);

	if (d < prevd) {

		float epsilon = 1.0f;
		Vec3 Normal = VMath::normalize(b2.pos - b1.pos);

		float VMag1 = VMath::dot(b1.vel, Normal);
		float VMag2 = VMath::dot(b2.vel, Normal);

		float VMagPrime1 = ((b1.mass - epsilon * b2.mass) * VMag1 + (1 + epsilon) * b2.mass * VMag2) / (b1.mass + b2.mass);
		float VMagPrime2 = ((b2.mass - epsilon * b1.mass) * VMag2 + (1 + epsilon) * b1.mass * VMag1) / (b1.mass + b2.mass);

		Vec3 FinalVelocity1 = (VMagPrime1 - VMag1) * Normal;
		Vec3 FinalVelocity2 = (VMagPrime2 - VMag2) * Normal;

		if (!b1.isStatic) b1.vel += FinalVelocity1;
		if (!b2.isStatic) b2.vel += FinalVelocity2;
	}
	prevd = d;

}
