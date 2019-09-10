#ifndef SCENE_H
#define SCENE_H
struct Scene {
	Scene(){}
	virtual ~Scene(){}

	virtual bool OnCreate() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void onDestroy() = 0;
};
#endif // !SCENE_H
