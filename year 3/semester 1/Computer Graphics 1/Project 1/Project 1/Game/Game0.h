#ifndef GAME0_H
#define GAME0_H

#include "../Engine/Core/Engine.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"

class Game0 : public GameInterface {
public:
	Game0();
	virtual ~Game0();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime);
	virtual void Render();
	virtual void onDestroy();
private:
	int sceneNumber;
	Scene* currentScene;

	void BuildScene();
};

#endif // !GAME0_H
