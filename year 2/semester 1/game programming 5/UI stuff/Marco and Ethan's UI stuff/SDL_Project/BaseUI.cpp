#include "BaseUI.h"
#include <SDL_image.h>

BaseUI::BaseUI(char* imageName, Vec3 pos_, bool display_) {

	//the position of the ui elements we create
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;
	//weither element should be displayed or not
	display = display_;
	//if image isnt set for the ui element
	bodyImage = IMG_Load(imageName);
	if (bodyImage == nullptr) {
	}

}

BaseUI::~BaseUI() {} 

SDL_Surface* BaseUI::getImage() {
	return bodyImage;
}