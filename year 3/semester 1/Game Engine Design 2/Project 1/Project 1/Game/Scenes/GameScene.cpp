#include "GameScene.h"
#include <iostream>



GameScene::GameScene(){
}


GameScene::~GameScene() {
}

bool GameScene::OnCreate() {
	Vertex v;
	//Triangle1
	std::vector<Vertex> vertList;
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertList.push_back(v);

	Model* triangleModel = new Model();
	triangleModel->AddMesh(new Mesh(&vertList));
	triangle = new GameObject(triangleModel);

	//Triangle2
	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertList.push_back(v);
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertList.push_back(v);

	Model* triangleModel2 = new Model();
	triangleModel2->AddMesh(new Mesh(&vertList));
	triangle2 = new GameObject(triangleModel2);

	return true;
}

void GameScene::Update(const float deltaTime) {
}

void GameScene::Render() {
	triangle->Render();
	triangle2->Render();
}

void GameScene::onDestroy() {
	delete triangle, triangle2;
	triangle, triangle2 = nullptr;
}
