#include "SceneGraph.h"
#include "3D\Model.h"
#include "3D\GameObject.h"

std::unique_ptr<SceneGraph> SceneGraph::instance = nullptr;
std::map<std::string, GameObject*> SceneGraph::sceneGameObjects = std::map<std::string, GameObject*>();
std::map<GLuint, std::vector<Model*>> SceneGraph::sceneModels = std::map<GLuint, std::vector<Model*>>();

SceneGraph * SceneGraph::getInstance() {
	if(instance == nullptr) {
		instance.reset(new SceneGraph);
	}
	return instance.get();
}

void SceneGraph::addGameObject(GameObject * g, std::string name) {
	if(name == "") {
		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		g->setTag(newName);
		sceneGameObjects[newName] = g;
	}
	else if(sceneGameObjects.find(name) == sceneGameObjects.end()) {
		g->setTag(name);
		sceneGameObjects[name] = g;
	}
	else {
		Debug::warning("Replaced gameobject with name " + name + " that already existed.", __FILE__, __LINE__);
		std::string newName = "GameObject" + std::to_string(sceneGameObjects.size() + 1);
		g->setTag(newName);
		sceneGameObjects[newName] = g;
	}
}

void SceneGraph::addModel(Model * m) {
	if(sceneModels.find(m->getShaderProgram()) == sceneModels.end()) {
		sceneModels.insert(std::pair < GLuint, std::vector<Model*>>(
			m->getShaderProgram(),
			std::vector<Model*>({m})
			)
		);
	}
	else {
		sceneModels[m->getShaderProgram()].push_back(m);
	}
}

GameObject * SceneGraph::getGameObject(std::string name) {
	if(sceneGameObjects.find(name) == sceneGameObjects.end()) {
		return sceneGameObjects[name];
	};
	return nullptr;
}

void SceneGraph::Update(const float deltaTime) {

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
