#include "GameScene.h"
#include <iostream>
#include "../../Engine/Graphics/ShaderHandler.h"



GameScene::GameScene() {
	OnCreate();
}


GameScene::~GameScene() {
	onDestroy();
}

bool GameScene::OnCreate() {
	camera = new Camera();
	camera->setPosition(glm::vec3(0.0f,0.0f, 4.0f));

	Vertex v;
	//Triangle
	std::vector<Vertex> vertexList;
	{
		v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.583f, 0.771f, 0.014f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.609f, 0.115f, 0.436f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.327f, 0.483f, 0.844f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.822f, 0.569f, 0.201f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.435f, 0.602f, 0.223f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.310f, 0.747f, 0.185f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.597f, 0.770f, 0.761f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.559f, 0.436f, 0.730f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.359f, 0.583f, 0.152f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.483f, 0.596f, 0.789f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.559f, 0.861f, 0.639f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.195f, 0.548f, 0.859f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.014f, 0.184f, 0.576f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.771f, 0.328f, 0.970f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.406f, 0.615f, 0.116f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.676f, 0.977f, 0.133f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.971f, 0.572f, 0.833f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.140f, 0.616f, 0.489f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.997f, 0.513f, 0.064f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.945f, 0.719f, 0.592f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.543f, 0.021f, 0.978f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.279f, 0.317f, 0.505f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.167f, 0.620f, 0.077f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.347f, 0.857f, 0.137f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, -1.0f);
		v.colour = glm::vec3(0.055f, 0.953f, 0.042f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.714f, 0.505f, 0.345f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.783f, 0.290f, 0.734f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.722f, 0.645f, 0.174f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.302f, 0.455f, 0.848f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.225f, 0.587f, 0.040f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.517f, 0.713f, 0.338f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, -1.0f);
		v.colour = glm::vec3(0.053f, 0.959f, 0.120f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.393f, 0.621f, 0.362f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.673f, 0.211f, 0.457f);
		vertexList.push_back(v);
		v.position = glm::vec3(-1.0f, 1.0f, 1.0f);
		v.colour = glm::vec3(0.820f, 0.883f, 0.371f);
		vertexList.push_back(v);
		v.position = glm::vec3(1.0f, -1.0f, 1.0f);
		v.colour = glm::vec3(0.982f, 0.099f, 0.879f);
		vertexList.push_back(v);
	}
	/*v.position = glm::vec3(0.5f, 0.5f, 0.0f);
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
	vertList.push_back(v);*/

	triangleModel = new Model(ShaderHandler::getInstance()->getShader("colourShader"));
	triangleModel->AddMesh(new Mesh(&vertexList, ShaderHandler::getInstance()->getShader("colourShader")));
	triangleModel->setScale(glm::vec3(0.25f, 0.25f, 0.25f));
	triangleModel->setRotation(glm::vec3(0.5f, 0.5f, 0.0f));
	triangle = new GameObject(triangleModel);

	return true;
}

void GameScene::Update(const float deltaTime) {
	triangleModel->setAngle(triangleModel->GetAngle() + 0.05f);
}

void GameScene::Render() {
	triangle->Render(camera);
}

void GameScene::onDestroy() {
	delete triangle;
	triangle = nullptr;

	delete triangleModel;
	triangleModel = nullptr;

	delete camera;
	camera = nullptr;
}
