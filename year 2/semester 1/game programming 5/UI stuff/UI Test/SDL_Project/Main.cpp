#include <iostream>
#include <memory>
#include "GameManager.h"
#include "MMath.h"
///#include <SDL.h>
using namespace MATH;

int main(int argc, char* args[]) { /// Standard C-style entry point, you need to use it
	//printf("%d\n", sizeof(SDL_Event));
	GameManager *ptr = new GameManager();
	//auto ptr = std::unique_ptr<GameManager>(new GameManager());
	//auto ptr = make_unique<GameManager>(GameManager());
	bool status  = ptr->OnCreate();
	if (status == true) {
	ptr->Run();
	} else if (status == false) {
		/// You should have learned about stderr (std::cerr) in Operating Systems 
		std::cerr << "Fatal error occured. Cannot start this program" << std::endl;
	}
	delete ptr;
	return 0;

}

//template<class T, class U>
//std::unique_ptr<T> make_unique(U&&u) {
//	return std::unique_ptr<T>(new T(std::forward<U>(u)));
//}




