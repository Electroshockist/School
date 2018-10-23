#ifndef UIPARENT_H
#define UIPARENT_H
#include <SDL.h>

class UIParent
{
public:
	virtual bool oncreate() = 0;
	
	virtual void render() = 0;
	
};
#endif 
