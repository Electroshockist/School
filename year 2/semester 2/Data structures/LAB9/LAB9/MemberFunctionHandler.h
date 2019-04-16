/* 
	Class:		MemberFunctionHandler
	Purpose:	Implements callback functionality by invoking a member function
				for an instance
*/

#ifndef MEMBERFUNCTIONHANDLER_H
#define MEMBERFUNCTIONHANDLER_H

#include "Event.h"
#include "BaseFunctionHandler.h"

template <class T, class EventT>
class MemberFunctionHandler : public BaseFunctionHandler
{
	public:
		//Redefine function pointer
		typedef void (T::*MemberFunc)(EventT*);

		MemberFunctionHandler(T* instance, MemberFunc memFn) : _instance(instance), _function(memFn) 
		{ }

		//Execute member call invocation for an instance of an object
		void call(const Event* event)
		{
			(_instance->*_function)(static_cast<EventT*>(event));
		}

	private:
		//Object pointer
		T* _instance;
		//Member function pointer
		MemberFunc _function;
};

#endif