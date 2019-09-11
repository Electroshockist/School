#include "Core/Engine.h"
#include "../Game/Game0.h"
#include "iostream"


int main(int argc, char* argv[]) {
	Engine::getInstance()->setGameInterface(new Game0());
	Debug::setProjectPath(argv[0]);
	Debug::info("ok", __FILE__, __LINE__);

	if (!Engine::getInstance()->OnCreate("test", 1280, 720)) {
		std::cout << "Window creation failed" << std::endl;
		return 1;
	}
	Engine::getInstance()->Run();

	return 0;
}