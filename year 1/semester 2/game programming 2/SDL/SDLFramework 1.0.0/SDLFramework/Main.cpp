#include <stdio.h>
#include <SDL.h>
#include "Window.h"

/// Create the standard 4:3 game window dimensions
/// "const" is considered better than define statements,
/// notice that these variables are global within this file 
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* args[]) { /// Standard C-style entry point, you need to use it
	Window* w = new Window(SCREEN_WIDTH,SCREEN_HEIGHT);

	delete w;
	w = nullptr;

	exit(0);
}