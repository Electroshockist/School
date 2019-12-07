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
#include <glm/gtc/type_ptr.hpp>

Scene2::Scene2() :
	camera(nullptr), earthGameObject(nullptr), earthMeshPtr(nullptr), earthShaderPtr(nullptr), earthTexturePtr(nullptr), moonGameObject(nullptr), moonMeshPtr(nullptr), moonShaderPtr(nullptr), moonTexturePtr(nullptr) {}

Scene2::~Scene2() {}

bool Scene2::OnCreate() {
	camera = new Camera();
	CreateNoise3D();

	if(ObjLoader::loadOBJ("skull.obj") == false) {
		return false;
	}

	earthMeshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	earthShaderPtr = new Shader("noiseVert.glsl", "noiseFrag.glsl");
	earthTexturePtr = new Texture();
	if(earthMeshPtr == nullptr || earthShaderPtr == nullptr || earthTexturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	if(earthTexturePtr->LoadImage("earthclouds.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	earthGameObject = new GameObject(earthMeshPtr, earthShaderPtr, earthTexturePtr);
	if(earthGameObject == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	//moon
	moonMeshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	moonShaderPtr = new Shader("textureVert.glsl", "textureFrag.glsl");
	moonTexturePtr = new Texture();

	if(moonMeshPtr == nullptr || moonShaderPtr == nullptr || moonTexturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	if(moonTexturePtr->LoadImage("moon.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	moonGameObject = new GameObject(moonMeshPtr, moonShaderPtr, moonTexturePtr);
	if(moonGameObject == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}

	lightSource = Vec3(30.0, 0.0, 1.0);


	//fabric = new Fabric(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);

	//fabricTexturePtr = new Texture();

	//if(fabric == nullptr || fabric->getShader() == nullptr || fabricTexturePtr == nullptr) {
	//	Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
	//	return false;
	//}

	//if(fabricTexturePtr->LoadImage("moon.jpg") == false) {
	//	Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
	//	return false;
	//}

	//fabricObject = new GameObject(fabric, fabric->getShader(), fabricTexturePtr);
	//fabricObject->setModelMatrix(MMath::translate(Vec3(5, 0, 0)));

	lightSource = Vec3(30.0, 0.0, 1.0);



	return true;
}

void Scene2::OnDestroy() {
	if(camera) delete camera, camera = nullptr;
	if(earthMeshPtr) delete earthMeshPtr, earthMeshPtr = nullptr;
	if(earthTexturePtr) delete earthTexturePtr, earthTexturePtr = nullptr;
	if(earthShaderPtr) delete earthShaderPtr, earthShaderPtr = nullptr;
	if(earthGameObject) delete earthGameObject, earthGameObject = nullptr;

	if(moonMeshPtr) delete moonMeshPtr, moonMeshPtr = nullptr;
	if(moonTexturePtr) delete moonTexturePtr, moonTexturePtr = nullptr;
	if(moonShaderPtr) delete moonShaderPtr, moonShaderPtr = nullptr;
	if(moonGameObject) delete moonGameObject, moonGameObject = nullptr;

	if(fabric) delete fabric, fabric = nullptr;
}

void Scene2::HandleEvents(const SDL_Event &sdlEvent) {
	camera->handleEvents(sdlEvent);
}

void Scene2::Update(const float deltaTime_) {
	deltaTime = deltaTime_;
	elapsedTime += deltaTime_;
	//move camera back
	camZ += 0.25f * deltaTime_;
	camera->setPos(Vec3(0.0f, 0.0f, camZ));

	earthGameObject->Update(deltaTime_);
	static float rotation = 0.0f;
	rotation += 0.5;

	Matrix4 rotationMatrix =
		MMath::rotate(rotation, Vec3(0.0, 1.0, 0.0));

	moonGameObject->Update(deltaTime_);
	moonGameObject->setModelMatrix(
		//MMath::rotate(-90, Vec3(1.0, 0.0, 0.0)) *
		rotationMatrix *
		MMath::translate(Vec3(10, 0, 0)) *
		MMath::scale(0.25, 0.25, 0.25) *
		MMath::rotate(-90, Vec3(0.0, 1.0, 0.0))
	);
	earthGameObject->setModelMatrix(
		/*MMath::rotate(-90, Vec3(1.0 * rotation, 0.0, 0.0))* rotationMatrix*/
		rotationMatrix * MMath::rotate(90, Vec3(0.0, 1.0, 0.0))
	);

}

void Scene2::Render() const {

	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	camera->render();

	/// Draw your scene here
	GLuint program = earthGameObject->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(earthGameObject->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(earthGameObject->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniformMatrix3fv(earthGameObject->getShader()->getUniformID("cameraPos"), 1, GL_FALSE, camera->getPos());
	glUniform1f(earthGameObject->getShader()->getUniformID("time"), elapsedTime);

	glm::vec3 v = glm::vec3(lightSource.x, lightSource.y, lightSource.z);
	glUniform3fv(earthGameObject->getShader()->getUniformID("lightPos"), GL_FALSE, glm::value_ptr(v));

	earthGameObject->Render();
	moonGameObject->Render();

	//	//fabric
	//	program = fabric->getShader()->getProgram();
	//	glUseProgram(program);
	//
	//	/// These pass the matricies and the light position to the GPU
	//	glUniformMatrix4fv(fabric->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	//	glUniformMatrix4fv(fabric->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	//	glUniformMatrix3fv(fabric->getShader()->getUniformID("cameraPos"), 1, GL_FALSE, camera->getPos());
	//	glUniform1f(fabric->getShader()->getUniformID("time"), elapsedTime);
	//	glUniform1f(fabric->getShader()->getUniformID("deltaTime"), deltaTime);
	//	glUniform1f(fabric->getShader()->getUniformID("gravity"), -9.81f);
	//
	//	glUniform3fv(fabric->getShader()->getUniformID("lightPos"), GL_FALSE, glm::value_ptr(v));
	//
	//	fabricObject->Render();
	//
	//	glUseProgram(0);
}
