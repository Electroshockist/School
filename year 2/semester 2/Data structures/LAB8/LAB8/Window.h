#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <stdlib.h>
#include <gl/glut.h>

#include "MouseEvent.h"
#include "MouseAdapter.h"

using namespace std;

class Window
{
	public:
		Window(string title, int posX, int posY)
		{
		   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
		   glutInitWindowSize(posX, posY);
		   glutCreateWindow(title.c_str());
		   glutDisplayFunc(Window::initDisplay);
		}

		//Implements functionality for mouse button click an mouse motion
		void addEventListener(string event)
		{
			if (event == MouseEvent::MOUSE_PRESSED)
				glutMouseFunc(&MouseAdapter::mouseClicked);
			else if (event == MouseEvent::MOUSE_MOVED)
				glutMotionFunc(&MouseAdapter::mouseMoved);
		}

		//Starts OpenGL Window
		void draw()
		{
			glutMainLoop();
		}

	private:
		//Initializes Display
		//Optional Implementation
		static void initDisplay()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glutSwapBuffers();
		}
};

#endif