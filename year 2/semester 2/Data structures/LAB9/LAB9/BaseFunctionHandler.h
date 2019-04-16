/* 
	Class:		BaseFunctionHandler
	Purpose:	Abstract class which applies the Command design pattern
*/

#ifndef BASEFUNCTIONHANDLER_H
#define BASEFUNCTIONHANDLER_H

#include "Event.h"

class BaseFunctionHandler
{
	public:
		virtual ~BaseFunctionHandler() 
		{ }
		
		void exec(const Event* event) 
		{
			call(event);
		}

	private:
		virtual void call(const Event*) = 0;
};

#endif