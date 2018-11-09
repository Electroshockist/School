#pragma once
#include "UI.h"
#include "RpgUI.h"
#include "HackSlashUI.h"

class UIFactory {
	public:
		static inline UI* buildUI(int arg) {
			if (arg == 1) return new RpgUI();

			if (arg == 2)return new HackSlashUI();
		}

};
