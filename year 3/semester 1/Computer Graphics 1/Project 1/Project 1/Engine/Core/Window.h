#ifndef WINDOW_H

#define WINDOW_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>

#include <string>

class Window {
	int width, height;
	SDL_Window* window;
	SDL_GLContext context;

	void setAttributes();
public:
	Window();
	~Window();

	bool OnCreate(std::string name, int width, int height);
	void OnDestroy();

	int getHeight() const;
	int getWidth() const;
	SDL_Window* getWindow() const;

};
#endif // !WINDOW_H

