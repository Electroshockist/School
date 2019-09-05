#include "Core/Engine.h"
#include "iostream"


int main(int argc, char* argv[]) {

	if (!Engine::getInstance()->OnCreate("test", 1280, 720)) {
		std::cout << "Window creation failed" << std::endl;
		return 1;
	}
	Engine::getInstance()->Run();

	return 0;
}