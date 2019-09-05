#ifndef ENGINE_H
#define ENGINE_H


#include "Window.h"
#include <memory>


class Engine {
	Engine();
	~Engine();

	Window* window;
	bool isRunning;

	static std::unique_ptr<Engine> instance;
	friend std::default_delete<Engine>;

	void Update(const float deltaTime);
	void Render();
	void OnDestroy();
public:
	//delete constructors for singleton
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(Engine&&) = delete;

	bool OnCreate(std::string name, int width, int height);
	void Run();
	bool getIsRunning();
	static Engine* getInstance();
};
#endif // !ENGINE_H

