#ifndef MOUSEADAPTER_H
#define MOUSEADAPTER_H

#include <iostream>
#include <string>

#include "MouseEvent.h"

using namespace std;

class MouseAdapter
{
	public:
		//Mouse Click Adapter Method
		//INSERT CODE HERE
		static void mouseClicked(int button, int state, int x, int y)
		{
			//Declare a string button state
			string buttonState;

			//Set the mouse state to the button and state method parameters
			_mouse->setState(button, state);
			
			//Set the mouse new position to the x and y coordinate parameters
			_mouse->setNewPos(x, y);

			//If state is equal to GLUT_DOWN
			if (state == GLUT_DOWN)
				//Set the button state to Down
				buttonState = "Down";

			//Else
			else
				//Set the button state to Up
				buttonState = "Up";

			//Print output similar to mine!
			cout << "Mouse button " << buttonState << " at [" << x << ", " << y << "]" << endl;
		}

		//Mouse Move Adapter Method
		//INSERT CODE HERE
		static void mouseMoved(int x, int y)
		{
			//Set the mouse old position to be the "new" position, which is stored in _mouse
			_mouse->setOldPos(_mouse->getX(), _mouse->getY());

			//Set the new mouse position to the x and y coodinate parameters
			_mouse->setNewPos(x, y);

			//Print Mouse Drag Button

			//If _mouse button clicked is left
			if (_mouse->isLeft())

				//Print left
				cout << "Left Button";

			//Else if _mouse button clicked is right
			else if (_mouse->isRight())

				//Print right
				cout << "Right Button";

			//Else
			else

				//Print Middle
				cout << "Middle Button";
			
			//Print output similar to mine!
			cout << " dragged from" << endl << "\t\t[" << _mouse->getOldX() << ", " << _mouse->getOldY() << "]" << endl << "\t\t   to" << endl << "\t\t[" << _mouse->getX() << ", " << _mouse->getY() << "]" << endl;
		}

	private:
		static MouseEvent* _mouse;
};

//Instantiate the MouseEvent _mouse instance variable
//INSERT CODE HERE
MouseEvent* MouseAdapter::_mouse = new MouseEvent();


#endif