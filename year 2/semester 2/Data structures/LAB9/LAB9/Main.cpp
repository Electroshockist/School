#include "Window.h"

int main()
{
	Window* w = new Window("Event Notifier", 200, 200);

	delete w;

	return 0;
}