#include "DrawableSDL.h"
#include "Container.h"
SDL_Surface* DrawableSDL::surface;

DrawableSDL::DrawableSDL(void)
{
	parent = NULL;
}

void DrawableSDL::close()
{
	((Container*)parent)->remove(this);
}


DrawableSDL::~DrawableSDL(void)
{
}

bool DrawableSDL::isContain(int x, int y)
{
	if(real_x < x && x < real_x + w)
		if(real_y < y && y < real_y + h)
			return true;
	return false;
}

bool DrawableSDL::spreadEvent(SDL_Event e)
{
	switch(e.type)
	{
	case SDL_KEYDOWN:
		for(int i=0; i<handlers.size(); i++)
			if((handlers[i].getObject())->keyDown(e, this))
				return true;
		break;
	case SDL_KEYUP:
		for(int i=0; i<handlers.size(); i++)
			if((handlers[i].getObject())->keyUp(e, this))
				return true;
	case SDL_MOUSEBUTTONDOWN:
		if(isContain(e.button.x, e.button.y))
			pressed = true;
		for(int i=0; i<handlers.size(); i++)
			if(isContain(e.button.x, e.button.y))
			{
				if(handlers[i].getObject()->mouseDown(e, this))
					return true;
			}
		break;
	case SDL_MOUSEBUTTONUP:
		if(pressed)
			pressed = false;
		else
			return false;
		for(int i=0; i<handlers.size(); i++)
			if(!pressed)
			{
				handlers[i].getObject()->mouseUp(e, this);
				if(isContain(e.button.x, e.button.y))
				{
					return this->
						handlers[i].getObject()->
							onClick(e, this);
				}
				return true;
			}
	case SDL_MOUSEMOTION:
		for(int i=0; i<handlers.size(); i++)
			if(handlers[i].getObject()->mouseMove(e, this))
				return true;
	}
	return false;
}

void DrawableSDL::draw(int x, int y)
{
	this->real_x = x + this->x;
	this->real_y = y + this->y;
}