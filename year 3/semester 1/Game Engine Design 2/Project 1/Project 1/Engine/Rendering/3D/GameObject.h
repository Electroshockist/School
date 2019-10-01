
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"

class GameObject {
public:
	GameObject(Model* model_);
	~GameObject();
	void Render(Camera* camera);
	void OnDestroy();
private:
	Model* model;
};
#endif // !GAMEOBJECT_H



