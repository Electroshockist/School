#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "CollisionDetection.h"
#include "Ray.h"
#include "../Rendering/3D/GameObject.h"
#include "../Core/Engine.h"
#include "../Core/OctTree.h"

class CollisionHandler {	
	CollisionHandler();
	~CollisionHandler();

	static std::unique_ptr<CollisionHandler> collisionInstance;
	friend std::default_delete<CollisionHandler>;
	static std::vector<GameObject*> prevCollisions;
	static OctTree* octTree;

public:
	CollisionHandler(const CollisionHandler&) = delete;
	CollisionHandler(CollisionHandler&&) = delete;
	CollisionHandler& operator=(const CollisionHandler&) = delete;
	CollisionHandler& operator=(CollisionHandler&&) = delete;

	static CollisionHandler* GetInstance();

	void OnCreate(float WorldSize);
	void AddObject(GameObject* gameObject_);
	void Update(glm::vec2 mousePosition_, int buttonType_);
	void OnDestroy();
};

#endif