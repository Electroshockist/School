class Body;
class Collider
{
public:
	// Detects collisions between triangles
	static bool Collided(const Body& b1, const Body& b2);

	// Collision response based on contact points, contact normal and Body data. Not needed for this assignment…
	static void HandleCollision(Body& b1, Body& b2);
};

