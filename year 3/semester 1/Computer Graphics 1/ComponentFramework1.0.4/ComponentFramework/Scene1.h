#ifndef SCENE1_H
#define SCENE1_H
#include "Scene.h"
#include "Scene.h"
#include "Vector.h"

using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Camera;
class GameObject;
class Mesh;
class Shader;
class Texture;
class SkyBox;

class Scene1 : public Scene {
public:
private:
	Camera *camera;
	GameObject *earthGameObject;
	GameObject *moonGameObject;
	Vec3 lightSource;

	Mesh *earthMeshPtr;
	Shader *earthShaderPtr;
	Texture *earthTexturePtr;

	Mesh *moonMeshPtr;
	Shader *moonShaderPtr;
	Texture *moonTexturePtr;
	float camZ = 10.0f;

public:
	explicit Scene1();
	virtual ~Scene1();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime_) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // !SCENE1_H