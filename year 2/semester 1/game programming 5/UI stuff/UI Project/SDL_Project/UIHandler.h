#pragma once
#include "Assignment1.h"
#include "UIFactory.h"

class UIHandler {
	public:
		inline static void changeUI(int arg, Assignment1* scene_) {
			scene_->SetUI(UIFactory::buildUI(arg));
		}
};

