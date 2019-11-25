#include "SceneGraph.h"
#include "3D\Model.h"
#include "3D\GameObject.h"
#include "../Math/CollisionHandler.h"

std::unique_ptr<SceneGraph> SceneGraph::instance = nullptr;
std::map<std::string, GameObject*> SceneGraph::sceneGameObjects = std::map<std::string, GameObject*>();
std::map<GLuint, std::vector<Model*>> SceneGraph::sceneModels = std::map<GLuint, std::vector<Model*>>();

SceneGraph * SceneGraph::getInstance() {
	if(instance == nullptr) {
		instance.reset(new SceneGraph);
	}
	return instance.get();
}

void SceneGraph::addGameObject(GameObject * gameObject, std::string name) {
	if(name == "") {
		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		gameObject->setTag(newName);
		sceneGameObjects[newName] = gameObject;
	}
	else if(sceneGameObjects.find(name) == sceneGameObjects.end()) {
		gameObject->setTag(name);
		sceneGameObjects[name] = gameObject;
	}
	else {
		Debug::warning("Replaced gameobject with name " + name + " that already existed.", __FILE__, __LINE__);
		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		gameObject->setTag(newName);
		sceneGameObjects[newName] = gameObject;
	}
	CollisionHandler::GetInstance()->AddObject(gameObject);
}

void SceneGraph::addModel(Model * model) {
	if(sceneModels.find(model->getShaderProgram()) == sceneModels.end()) {
		sceneModels.insert(std::pair < GLuint, std::vector<Model*>>(
			model->getShaderProgram(),
			std::vector<Model*>({model})
			)
		);
	}
	else {
		sceneModels[model->getShaderProgram()].push_back(model);
	}
}

GameObject * SceneGraph::getGameObject(std::string name) {
	if(sceneGameObjects.find(name) != sceneGameObjects.end()) {
		return sceneGameObjects[name];
	};
	return nullptr;
}

void SceneGraph::Update(const float deltaTime) {
	for (auto gameObject : sceneGameObjects) {
		gameObject.second->Update(deltaTime);
	}
}

void SceneGraph::Render(Camera * camera) {
	for(auto entry : sceneModels) {
		glUseProgram(entry.first);
		for(auto m : entry.second) {
			m->render(camera);
		}
	}
}

void SceneGraph::onDestroy() {
	if(sceneGameObjects.size() > 0) {
		for(auto go : sceneGameObjects) {
			delete go.second;
			go.second = nullptr;
		}
		sceneGameObjects.clear();
	}

	if(sceneModels.size() > 0) {
		for(auto entry : sceneModels) {
			if(entry.second.size() > 0) {
				for(auto m : entry.second) {
					delete m;
					m = nullptr;
				}
				entry.second.clear();
			}
		}
		sceneModels.clear();
	}
}

SceneGraph::SceneGraph() {}


SceneGraph::~SceneGraph() {
	onDestroy();
}
