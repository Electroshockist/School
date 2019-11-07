#ifndef EVENTLISTENER
#define EVENTLISTENER

#include "MouseEventListener.h"

class Engine;
class EventListener {
public:
		//delete constructors for singleton
	EventListener() = delete;
	EventListener(const EventListener&) = delete;
	EventListener(EventListener&&) = delete;
	EventListener& operator=(const EventListener&) = delete;
	EventListener& operator=(EventListener&&) = delete;
	~EventListener();

	static void update();
};
#endif // !EVENTLISTENER

