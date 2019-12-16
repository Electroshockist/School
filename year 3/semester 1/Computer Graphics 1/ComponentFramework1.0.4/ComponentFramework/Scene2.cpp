#include <iostream>
#include "Window.h"
#include "Debug.h"
#include "Scene2.h"
#include "Camera.h"
#include "GameObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Fabric/Fabric.h"
#include <glm/glm.hpp>

Scene2::Scene2() :
	camera(nullptr), fabric(nullptr), fabricMeshPtr(nullptr), fabricObject(nullptr), fabricTexturePtr(nullptr) {}

Scene2::~Scene2() {}

bool Scene2::OnCreate() {
	camera = new Camera();
	CreateNoise3D();

	if(ObjLoader::loadOBJ("sphere.obj") == false) {
		return false;
	}

	fabric = new Fabric(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	fabricTexturePtr = new Texture();
	if(fabricTexturePtr->LoadImage("moon.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	if(fabric == nullptr || fabric->getShader() == nullptr || fabricTexturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	fabricObject = new GameObject(fabric, fabric->getShader(), fabricTexturePtr);

	return true;
}

void Scene2::OnDestroy() {
	if(camera) delete camera, camera = nullptr;

	if(fabricObject) delete fabricObject, fabricObject = nullptr;
	if(fabricTexturePtr) delete fabricTexturePtr, fabricTexturePtr = nullptr;
	if(fabricMeshPtr) delete fabricMeshPtr, fabricMeshPtr = nullptr;
	if(fabric) delete fabric, fabric = nullptr;
}

void Scene2::HandleEvents(const SDL_Event &sdlEvent) {
	camera->handleEvents(sdlEvent);
}

void Scene2::Update(const float deltaTime) {
	this->deltaTime = deltaTime;
	elapsedTime += deltaTime;
	//move camera back
	camZ += 0.25f * deltaTime;
	camera->setPos(Vec3(0.0f, 0.0f, camZ));

	fabric->update(deltaTime);
}

void Scene2::Render() const {

	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	camera->render();
	/// Draw your scene here	 

	//fabric
	GLuint program = fabric->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(fabric->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(fabric->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniformMatrix3fv(fabric->getShader()->getUniformID("cameraPos"), 1, GL_FALSE, camera->getPos());
	glUniform1f(fabric->getShader()->getUniformID("time"), elapsedTime);
	glUniform1f(fabric->getShader()->getUniformID("deltaTime"), deltaTime);
	glUniform1f(fabric->getShader()->getUniformID("gravity"), -9.81f);

	fabricObject->Render();

	glUseProgram(0);
}
