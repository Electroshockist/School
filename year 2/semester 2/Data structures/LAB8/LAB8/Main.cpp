#include <stdlib.h>

#include "MouseEvent.h"
#include "MouseAdapter.h"
#include "Window.h"

using namespace std;

int main ()
{
	Window *w = new Window("Adapter Lab", 250, 250);
   
	w->addEventListener(MouseEvent::MOUSE_PRESSED);
	w->addEventListener(MouseEvent::MOUSE_MOVED);

	w->draw();

	delete w;

	return 0;
}
