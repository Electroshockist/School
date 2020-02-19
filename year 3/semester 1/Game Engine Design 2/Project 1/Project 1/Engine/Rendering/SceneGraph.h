#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <memory>
#include <map>
#include <vector>
#include <glew.h>
#include <string>

class Model;
class GameObject;
class Camera;
class SceneGraph {
public:
	static SceneGraph* getInstance();
	void addGameObject(GameObject* g, std::string name = "");
	void addModel(Model* m);
	GameObject* getGameObject(std::string name);

	void Update(const float deltaTime);
	void Render(Camera* camera);

	void onDestroy();

private:
	static std::map<std::string, GameObject*> sceneGameObjects;
	static std::map<GLuint, std::vector<Model*>> sceneModels;

	SceneGraph();
	~SceneGraph();

public:
	static std::unique_ptr<SceneGraph> instance;
	friend std::default_delete<SceneGraph>;


	//delete constructors for singleton
	SceneGraph(const SceneGraph&) = delete;
	SceneGraph(SceneGraph&&) = delete;
	SceneGraph& operator=(const SceneGraph&) = delete;
	SceneGraph& operator=(SceneGraph&&) = delete;
};


#endif // !SCENEGRAPH_H

