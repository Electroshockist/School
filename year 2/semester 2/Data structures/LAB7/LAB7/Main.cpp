#include <iostream>

#include "Controller.h"

using namespace std;

int main()
{
	Controller *c1 = Controller::getInstance();
	Controller *c2 = Controller::getInstance();
	Controller *c3 = Controller::getInstance();
	Controller *c4 = Controller::getInstance();
	Controller *c5 = Controller::getInstance();

	if(c5 == NULL)
		cout << "Controller 5 does not exist" << endl;

	return 0;
}