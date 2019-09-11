#ifndef ENGINE_H
#define ENGINE_H

#include "GameInterfaceh.h"
#include "Scene.h"
#include "Window.h"
#include "Debug.h"
#include "Timer.h"

#include <memory>

class Engine {
	Engine();
	~Engine();

	Timer timer;
	unsigned int fps;

	Window* window;
	bool isRunning;

	int currentScene;

	GameInterface* gameInterface;

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
	void setIsRuning(const bool isRunning);
	static Engine* getInstance();
	void setGameInterface(GameInterface* gameInterface);

	void setCurrentScene(int currentScene);
	int getCurrentScene() const;
};
#endif // !ENGINE_H

