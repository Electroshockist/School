/* 
	Class:		MouseEvent
	Purpose:	Implementation for a Mouse Event class defining
				Defines mouse state, button and location pressed
*/

#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <iostream>

#include <string>
#include <gl/glut.h>

#include "Event.h"

using namespace std;

class Window;

class MouseEvent : public Event
{
	public:
		MouseEvent() 
		{
			_oldX = -1;
			_oldY = -1;
			_currX = -1;
			_currY = -1; 
			_state = 0;
		}

		string setState(int btn, int ste = 0);

		void setNewPos(int x, int y);
		
		int isLeft() const           
		{
			return (_state & buttonLeft);
		}

		int isRight() const          
		{
			return (_state & buttonRight);
		}

		int isMiddle() const         
		{
			return (_state & buttonMiddle);
		}

		void reset()                 
		{
			_state = 0;
		}

		int getOldX() const          
		{
			return _oldX;
		}
		
		int getOldY() const          
		{
			return _oldY;
		}
		
		int getX() const             
		{
			return _currX;
		}
		
		int getY() const             
		{
			return _currY;
		}
		
		int getDiffX(int x) const        
		{
			return x - _oldX;
		}
		
		int getDiffY(int y) const        
		{
			return y - _oldY;
		}
		
		int getDiffX() const         
		{
			return _currX - _oldX;
		}
		
		int getDiffY() const         
		{
			return _currY - _oldY;
		}

		void setOldPos(int x, int y)     
		{
			_oldX = x; 
			_oldY = y;
		}

		static string MOUSE_PRESSED;
		static string MOUSE_RELEASED;
		static string MOUSE_MOVED;

	protected:
		enum
		{
			buttonLeft = 1,
			buttonRight = 2,
			buttonMiddle = 4,
		};

		int _state;
		int _oldX;
		int _oldY;
		int _currX;
		int _currY;
};

string MouseEvent::MOUSE_PRESSED = "mousePressed";
string MouseEvent::MOUSE_RELEASED = "mouseReleased";
string MouseEvent::MOUSE_MOVED = "mouseMoved";

string MouseEvent::setState(int btn, int ste)
{
   if(ste == GLUT_DOWN)
   {
      switch(btn)
      {
         case GLUT_LEFT_BUTTON:
            _state |= buttonLeft;
			break;
         case GLUT_RIGHT_BUTTON:
            _state |= buttonRight;
			break;
         case GLUT_MIDDLE_BUTTON:
            _state |= buttonMiddle;
			break;
      }

	  return MouseEvent::MOUSE_PRESSED;
   }
   else if(ste == GLUT_UP)
   {
      switch(btn)
      {
         case GLUT_LEFT_BUTTON:
            _state &= ~buttonLeft;
			break;
         case GLUT_RIGHT_BUTTON:
            _state &= ~buttonRight;
			break;
         case GLUT_MIDDLE_BUTTON:
            _state &= ~buttonMiddle;
			break;
      }

	  return MouseEvent::MOUSE_RELEASED;
   }
}

void MouseEvent::setNewPos(int x, int y)
{
   _currX = x;
   _currY = y;
}

#endif