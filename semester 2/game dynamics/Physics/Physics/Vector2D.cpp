#include "Vector2D.h"

Vector2D::Vector2D() {
	SetZero();
}

Vector2D::Vector2D(double newx, double newy) {
	Set(newx, newy);
}
void Vector2D::Set(double newx, double newy) {
	x = newx;
	y = newy;
}

void Vector2D::SetZero() {
	Set(0.0, 0.0);
}