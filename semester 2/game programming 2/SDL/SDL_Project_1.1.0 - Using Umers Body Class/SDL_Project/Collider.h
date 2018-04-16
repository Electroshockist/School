class Body;
class Collider
{
public:
	bool Collided(Body& b1, Body& b2);
	static void HandleCollision(Body& b1, Body&b2);
};

