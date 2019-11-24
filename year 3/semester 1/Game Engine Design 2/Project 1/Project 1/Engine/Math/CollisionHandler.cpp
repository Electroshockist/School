#include "CollisionHandler.h"

std::unique_ptr<CollisionHandler> CollisionHandler::collisionInstance = nullptr;
std::vector<GameObject*> CollisionHandler::colliders = std::vector<GameObject*>();
std::vector<GameObject*> CollisionHandler::prevCollisions = std::vector<GameObject*>();

CollisionHandler::CollisionHandler() {}

CollisionHandler::~CollisionHandler() {
	OnDestroy();
}

CollisionHandler* CollisionHandler::GetInstance() {
	if(collisionInstance.get() == nullptr) {
		collisionInstance.reset(new CollisionHandler);
	}
	return collisionInstance.get();
}

void CollisionHandler::OnCreate() {
	prevCollisions.clear();
	colliders.clear();
}

void CollisionHandler::AddObject(GameObject* gameObject_) {
	colliders.push_back(gameObject_);
}

void CollisionHandler::Update(glm::vec2 mousePosition, int buttonType) {
	Ray mouseRay = CollisionDetection::screenPosToWorldRay(mousePosition, Engine::getInstance()->getScreenSize(),
														   Engine::getInstance()->getCamera());

	GameObject* hitResult = nullptr;
	float shortestDist = FLT_MAX;

	for(auto go : colliders) {
		if(mouseRay.isColliding(&go->getBoundingBox())) {
			if(mouseRay.intersectionDistance < shortestDist) {
				hitResult = go;
				shortestDist = mouseRay.intersectionDistance;
			}
		}
	}

	if(hitResult) {
		hitResult->setHit(true, buttonType);
	}

	for(auto prev : prevCollisions) {
		if(hitResult != prev && prev != nullptr) {
			prev->setHit(false, buttonType);
			prev = nullptr;
		}
	}
	prevCollisions.clear();

	if(hitResult) {
		prevCollisions.push_back(hitResult);
	}
}

void CollisionHandler::OnDestroy() {
	for(auto go : colliders) {
		go = nullptr;
	}
	colliders.clear();

	for(auto go : prevCollisions) {
		go = nullptr;
	}
	prevCollisions.clear();
}