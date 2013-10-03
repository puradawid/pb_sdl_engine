#include "FramedRect.h"


FramedRect::FramedRect(void)
{
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
	this->border = 0;
}

FramedRect::FramedRect(int x, int y, int w, int h, int border)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->border = border;
}

Uint32 FramedRect::convertColor(char r, char b, char g)
{
	return SDL_MapRGB(DrawableSDL::surface->format, r, g, b);
}

void FramedRect::setBackground(char r, char g, char b)
{
	this->backgroundColor = convertColor(r,g,b);
}

void FramedRect::setBorderColor(char r, char g, char b)
{
	this->borderColor = convertColor(r,g,b);
}

void FramedRect::setBorderSize(int size)
{
	this->border = size;
}

void FramedRect::draw(int x, int y)
{
	
	DrawableSDL::draw(x,y);

	SDL_Rect border;
	SDL_Rect fronter;

	fronter.x = this->x + x;
	fronter.y = this->y + y;
	fronter.w = w;
	fronter.h = h;

	border.x = x - this->border + this->x;
	border.y = y - this->border + this->y;
	border.w = w + 2*this->border;
	border.h = h + 2*this->border;

	SDL_FillRect(DrawableSDL::surface, &border, borderColor);
	SDL_FillRect(DrawableSDL::surface, &fronter, backgroundColor);
}

FramedRect::~FramedRect(void)
{
}
