#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "../../Engine/Core/Engine.h"

class StartScene : public Scene{
public:
	StartScene();

	~StartScene();
	virtual bool OnCreate();
	virtual void Update(const float deltaTime);
	virtual void Render();
	virtual void onDestroy();
};
#endif //!STARTSCENE_H

