/* 
	Class:		EventHandler
	Purpose:	Implements registerEventFunc to observe events
				Implements handleEvent to invoke events
*/

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <string>
#include <map>

#include "TypeInfo.h"
#include "Event.h"
#include "BaseFunctionHandler.h"
#include "MemberFunctionHandler.h"

using namespace std;

class EventHandler
{
	public:
		~EventHandler();

		void handleEvent(string eventType, const Event*);

		template<class T, class EventT>
		void registerEventFunc(string eventType, T*, void (T::*memFn)(EventT*));

	private:
		//Redifne a map to Handlers
		typedef map<string, BaseFunctionHandler*> Handlers;
		Handlers _handlers;
};

EventHandler::~EventHandler()
{
	Handlers::iterator it = _handlers.begin();
	
	while(it != _handlers.end())
	{
		delete it->second;
		++it;
	}

	_handlers.clear();
}

template <class T, class EventT>
void EventHandler::registerEventFunc(string eventType, T* obj, void (T::*memFn)(EventT*))
{
	_handlers[eventType] = new MemberFunctionHandler<T, EventT>(obj, memFn);
}

void EventHandler::handleEvent(string eventType, const Event* event)
{
	Handlers::iterator it = _handlers.find(eventType);

	if(it != _handlers.end())
	{
		it->second->exec(event);
	}
}

#endif