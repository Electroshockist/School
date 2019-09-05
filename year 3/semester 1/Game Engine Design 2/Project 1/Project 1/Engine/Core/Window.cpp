#include "Window.h"
#include <iostream>


Window::Window() {
}


Window::~Window(){
}

bool Window::OnCreate(std::string name, int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to init SDL" << std::endl;
		return false;
	}
	this->height = height;
	this->width = width;

	window = SDL_CreateWindow(name.c_str(), 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL
		);
	if (!window) {
		std::cout << "Failed to create window" << std::endl;
		return false;
	}
	context = SDL_GL_CreateContext(window);
	setAttributes();
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	glEnable(GL_DEPTH_TEST);

	return true;
}

void Window::OnDestroy() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
}

int Window::getWidth() const {
	return width;
}

int Window::getHeight() const {
	return height;
}

SDL_Window * Window::getWindow() const {
	return window;
}

void Window::setAttributes() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;
}
