#ifndef Vector2D_h
#define Vector2D_h

class Vector2D
{
public:
	Vector2D(); //constructor
	Vector2D(double newx, double newy); //constructor

	double x;
	double y;

	void Set(double newx, double newy);

	void SetZero();
};

#endif // !Vector2D_h