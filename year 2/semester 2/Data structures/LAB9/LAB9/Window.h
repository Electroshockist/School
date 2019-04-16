/* 
	Class:		Window
	Purpose:	Proxy class implementation - abstracts window implementation from interface
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

#include "WindowImp.h"

using namespace std;

class Window : public WindowImp
{
	public:
		Window(string title = "", int width = 0, int height = 0) : WindowImp(title, width, height) 
		{
			draw();
		}

		~Window()
		{ }

		void onPress(const MouseEvent *event)
		{
			cout << "Press: at (" << event->getX() << " " << event->getY() << ")" << endl;

			delete event;
		}

		void onRelease(const MouseEvent *event)
		{
			cout << "Release: at (" << event->getX() << " " << event->getY() << ")" << endl;

			delete event;
		}

		void onMouseMove(const MouseEvent *event)
		{
			cout << "Moved: to (" << event->getX() << " " << event->getY() << ")" << endl;

			delete event;
		}
};

#endif