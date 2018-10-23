#ifndef BaseUI_H
#define BaseUI_H
#include "Vector.h"
#include "SDL.h"
using namespace MATH; 

class BaseUI {
public:
	Vec3 pos;
	bool display;
	SDL_Surface *bodyImage;
	BaseUI(char* imageName, Vec3 pos_, bool display_);
	~BaseUI();


	SDL_Surface* getImage();

	/*

	notes!!!!!!!!!!!!!!!!!!!

	so UI cannot be rendered in the previous way done with scott if inheriting. if inheriting from baseui class than must define constructor properly
	when using the array of elements.

	remove array for ui assests? would force creation and deletion of objects individually.

	inheriting from baseui causes crashes or if working disables all fucntionality of project.

	screw it just use inheritence via sdl class, inheriting from my own class wont work, but i have managed to inherit from other classes... part marks? 0.5

	gamemanager is mostly unimportant to project other than starting and swapping scenes. not much there for kevin to look at

	tried to get sdl to print text to screen. wanted a rough dialouge system and such. health bar to have a variable that ticked down properly
	maybe even a timer...
	didnt work. for sdl to print text to scene must download another extension. instead used various pngs i made. in order for a clock to tick, it could have worked
	but would need multiple pngs and ui elements made/turned on and off... sloppy and not worth the hassle, could have done it though...

	kevin if your reading this, next time describe what you want out of your projects better.. umer goes into exact details, yours is too loose.
	made a lot of students myself included have trouble
	*/

};


#endif
