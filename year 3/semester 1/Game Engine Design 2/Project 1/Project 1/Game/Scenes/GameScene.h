#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../../Engine/Core/Scene.h"

class GameScene : public Scene {
public:
	GameScene();
	~GameScene();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime);
	virtual void Render();
	virtual void onDestroy();
};
#endif //!GAMESCENE_H

