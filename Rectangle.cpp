#include "Rectangle.h"
#include "SDL.h"

Rectangle::Rectangle(void)
{
	this->x = 0;
	this->y = 0;
	this->w = 100;
	this->h = 100;
}

void Rectangle::refreshRect()
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void Rectangle::setColor(char r, char g, char b)
{
	this->color = SDL_MapRGB(DrawableSDL::surface->format, r,g,b);
	refreshRect();
}

void Rectangle::draw(int x, int y)
{
	SDL_Rect drawRect;
	drawRect.x = this->x + x;
	drawRect.y = this->y + y;
	drawRect.w = w;
	drawRect.h = h;
	SDL_FillRect(surface, &drawRect, color);
}

Rectangle::~Rectangle(void)
{
}
