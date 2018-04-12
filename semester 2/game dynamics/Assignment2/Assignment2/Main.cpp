#include <iostream>
#include <string>
#include <fstream>
#include "World.h"

using namespace std; //removes need to used std:: on all output/input

int main() {
	Vector2D gravityAccel(0.0f, -9.8f);
	Vector2D windForce(0,0);

	World world1(gravityAccel, windForce);

	Body* body1 = new Body(2.0f);
	Body* body2 = new Body(4.0f);

	world1.addTwoBodies(body1, body2); //Adding 2 Bodies
	world1.bodies[0]->position.Set(0, 200); //Setting position of the first body
	world1.bodies[1]->position.Set(0, 200); //Setting position of 2nd Body

	ofstream myfile;
	myfile.open("Applied Force.csv", fstream::app, fstream::trunc);
	cout << "Time\tBody1 x Pos\tBody1 y Pos\tBody2 x Pos\tBody2 y Pos" << endl;
	myfile << "Time , Body1 x Pos , Body1 y Pos , Body2 x Pos , Body2 y Pos" << endl;
	while (world1.bodies[0]->position.y > 0.0 || world1.bodies[1]->position.y > 0.0) {
		cout <<
			world1.elapsedTime << "\t" <<
			world1.bodies[0]->position.x << "\t\t" <<
			world1.bodies[0]->position.y << "\t\t" <<
			world1.bodies[1]->position.x << "\t\t" <<
			world1.bodies[1]->position.y << endl;
		myfile <<
			world1.elapsedTime << "," <<
			world1.bodies[0]->position.x << "," <<
			world1.bodies[0]->position.y << "," <<
			world1.bodies[1]->position.x << "," <<
			world1.bodies[1]->position.y << endl;

		world1.Update(0.1);
	}
	myfile.close();//closes the fileStream

	getchar();
	return 0;
}