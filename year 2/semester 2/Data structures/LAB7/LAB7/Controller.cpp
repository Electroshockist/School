#include "Controller.h"

//Declare a static STL vector of Controller Pointers
//Name it _instance


Controller::Controller() 
{
	//Check if vector is empty


	//Allocate vector memory by reserving the vector Controller locations
	//Use vector's reserve(size) member function
	

	cout << "Controller Constructor" << endl;
}

Controller::~Controller() 
{
	cout << "Controller Destructor" << endl; 
}

Controller* Controller::getInstance()
{
	//Check if the vector is less than 4
	

	//Instantiate a temporary auto_ptr for Controller
		

	//Push the controller pointer into the vector
		

	cout << "Controller " << _instance.size() << " returned" << endl;
	
	//Else 
	
	cout << "Controller Exists" << endl;

	//Return the last item in the vector
	
}