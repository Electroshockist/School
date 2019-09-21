#include "Core/Engine.h"
#include "../Game/Game0.h"
#include "iostream"


int main(int argc, char* argv[]) {
	Engine::getInstance()->setGameInterface(new Game0());
	Debug::setProjectPath(argv[0]);

	if (!Engine::getInstance()->OnCreate("test", 1280, 720)) {
		Debug::fatalError("Failed to create engine", __FILE__, __LINE__);
		return 1;
	}
	Engine::getInstance()->Run();

	return 0;
}