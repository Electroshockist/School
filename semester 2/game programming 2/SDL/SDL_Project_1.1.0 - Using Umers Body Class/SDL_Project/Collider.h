class Body;
class Collider
{
public:
	//ask Scott how to convert Body* array to Body
	bool Collided(const Body* b1, const Body* b2);
	static void HandleCollision(Body& b1, Body& b2);
};

