#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <SDL.h>
#include "Scene.h"

class GameManager {
private:
	class Window *ptr;
	class Timer *timer;
	bool isRunning;
	Scene *currentScene;

public:
	GameManager();
	~GameManager();
	bool OnCreate();
	void OnDestroy();

	void Run();
};
#endif


