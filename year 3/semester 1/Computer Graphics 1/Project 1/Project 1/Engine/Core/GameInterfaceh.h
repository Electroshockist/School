#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

struct GameInterface {
	GameInterface() {}
	virtual ~GameInterface() {}

	virtual bool OnCreate() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void onDestroy() = 0;
};

#endif // !GAMEINTERFACE_H
