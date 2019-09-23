#include <glew.h>
#include <iostream>
#include "Window.h"
#include "Debug.h"
#include "Scene0.h"
#include "Camera.h"
#include "GameObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Scene0::Scene0() :
	camera(nullptr), gameObject(nullptr), meshPtr(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {}

Scene0::~Scene0() {}

bool Scene0::OnCreate() {
	camera = new Camera();

	if (ObjLoader::loadOBJ("sphere.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("myShaderVert.glsl", "myShaderFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}
	if (texturePtr->LoadImage("earthclouds.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}
	gameObject = new GameObject(meshPtr, shaderPtr, texturePtr);
	if (gameObject == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	lightSource = Vec3(3.0, 16.0, 1.0);
	lightSource1 = Vec3(-16.0, -3.0, 1.0);
	//lightSources[0] = Vec3(3.0, 16.0, 0.0);
	//lightSources[1] = Vec3(12.0, 6.0, 2.0);

	/*for (size_t i = 0; i < lightNum; i++) {
		lights[i] = lightSources[i].toGlVec3();
	}*/

	return true;
}

void Scene0::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (gameObject) delete gameObject, gameObject = nullptr;
}

void Scene0::HandleEvents(const SDL_Event &sdlEvent) {}

void Scene0::Update(const float deltaTime_) {
	gameObject->Update(deltaTime_);
	static float rotation = 0.0f;
	rotation += 0.5;
	gameObject->setModelMatrix(MMath::rotate(rotation, Vec3(0.0, 1.0, 0.0)));
}

void Scene0::Render() const {

	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/// Draw your scene here
	GLuint program = gameObject->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(gameObject->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(gameObject->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(gameObject->getShader()->getUniformID("lightPos"), 1, lightSource);
	glUniform3fv(gameObject->getShader()->getUniformID("lightPos1"), 1, lightSource1);
	//glUniform3fv(gameObject->getShader()->getUniformID("lightPos"), lightNum, glm::value_ptr(lights[0]));

	gameObject->Render();

	glUseProgram(0);
}
