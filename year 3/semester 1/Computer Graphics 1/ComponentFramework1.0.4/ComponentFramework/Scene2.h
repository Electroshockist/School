#ifndef Scene2_H
#define Scene2_H
#include "Scene.h"
#include "Vector.h"

GLuint CreateNoise3D();

using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Camera;
class GameObject;
class Mesh;
class Shader;
class Texture;
class SkyBox;
class Fabric;

class Scene2 : public Scene {
	Camera *camera;
	GameObject *fabricObject;

	Fabric *fabric;
	Texture *fabricTexturePtr;
	Mesh *fabricMeshPtr;
	
	float camZ = 10.0f;
	float elapsedTime = 0;
	float deltaTime = 0;

public:
	explicit Scene2();
	virtual ~Scene2();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime_) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // !Scene2_H