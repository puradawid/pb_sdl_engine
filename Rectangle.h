#pragma once
#include "drawablesdl.h"
#include "SDL.h"
class Rectangle :
	public DrawableSDL
{
protected:
	Uint32 color;
	SDL_Rect rect;
	void refreshRect();
public:
	Rectangle(void);
	void draw(int, int);
	void setColor(char r, char g, char b);
	~Rectangle(void);
};

