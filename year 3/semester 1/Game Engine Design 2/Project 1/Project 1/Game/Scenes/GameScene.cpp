#include "GameScene.h"
#include <iostream>
#include "../../Engine/Graphics/ShaderHandler.h"



GameScene::GameScene(){
}


GameScene::~GameScene() {
}

bool GameScene::OnCreate() {
	Vertex v;
	//Triangle
	std::vector<Vertex> vertList;
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(0.5f, 0.0f, 0.4f);
	vertList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);	
	v.colour = glm::vec3(0.5f, 0.3f, 0.0f);
	vertList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);	
	v.colour = glm::vec3(0.0f, 0.3f, 0.6f);
	vertList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(0.5f, 1.0f, 0.8f);
	vertList.push_back(v);
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);	
	v.colour = glm::vec3(1.0f, 0.0f, 0.4f);
	vertList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);	
	v.colour = glm::vec3(0.0f, 0.3f, 0.6f);
	vertList.push_back(v);

	Model* triangleModel = new Model(ShaderHandler::getInstance()->getShader("colourShader"));
	triangleModel->AddMesh(new Mesh(&vertList));
	triangle = new GameObject(triangleModel);

	return true;
}

void GameScene::Update(const float deltaTime) {
}

void GameScene::Render() {
	triangle->Render();
}

void GameScene::onDestroy() {
	delete triangle;
	triangle = nullptr;
}
