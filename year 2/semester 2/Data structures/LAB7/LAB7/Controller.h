#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Controller 
{
	public:
		static Controller* getInstance();

		~Controller();

	protected:
		Controller();

	private:
		static vector<Controller*> _instance;
};

#endif