#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../../Engine/Core/Engine.h"

class GameScene : public Scene {
	GameObject* object;
	Model* model;

public:
	GameScene();
	~GameScene();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime);
	virtual void Render();
	virtual void onDestroy();
};
#endif //!GAMESCENE_H

