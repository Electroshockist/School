#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../../Engine/Core/Engine.h"

class GameScene : public Scene {
	GameObject* triangle;
	GameObject* triangle2;
public:
	GameScene();
	~GameScene();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime);
	virtual void Render();
	virtual void onDestroy();
};
#endif //!GAMESCENE_H

