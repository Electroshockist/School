#include <string>
#include <iostream>
#include "World.h"
#include <fstream>

using namespace std;

int main() {
	double Mass = 200.0;
	Vector2D force(500.0,0.0);
	//sets all vectors to 0,0
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	Vector2D prevVel;

	const double timeStep = 0.5;

	Vector2D gravityAccel(0.0, -9.8);
	Vector2D windForce;

	Body* body1 = new Body(2.0);
	Body* body2 = new Body(4.0);

	World world1(gravityAccel, windForce);
	world1.addTwoBodies(body1, body2);
	ofstream myfile;
	myfile.open("example.csv");
	myfile << "Time , Posx1 , Posy1 , Posx2 , Posy2 " << endl;

	//cout << "World 1 Body 1: " << world1.bodies[0]->mass << endl;
	//cout << "World 1 Body 2: " << world1.bodies[1]->mass << endl;

	myfile.close();
	
	Body jetski(Mass, position, velocity, acceleration);

	cout << "Time\t\tForce\t\tPosition\t\tVelocity\t\tAcceleration" << endl;

	for (double totalTime = 0.0; totalTime < 15; totalTime += timeStep) {
		if(totalTime >= 10) {
			force.x = -625.0;
		}
		else if(totalTime > 5) {
			force.x = 0.0;
		}
		//sets jetski's acceleration
		jetski.ApplyForce(force);

		cout << totalTime << "\t\t" << force.x << "\t\t" << jetski.position.x << "\t\t\t" << jetski.velocity.x << "\t\t\t" << jetski.acceleration.x << endl;

		jetski.Update(timeStep);

		//keeps the current iteration of the loop's velocity to be used in the next iteration
		prevVel.x = jetski.velocity.x;
	}
	
	string s; //create string s
	cin >> s; //reads s
	return 0;
}