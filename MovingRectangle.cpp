#include "MovingRectangle.h"


MovingRectangle::MovingRectangle(void)
{
	
}

bool MovingRectangle::spreadEvent(SDL_Event e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
		case SDLK_UP:
			direction = up;
			return true;
		case SDLK_DOWN:
			direction = down;
			return true;
		case SDLK_RIGHT:
			direction = right;
			return true;
		break;
		case SDLK_LEFT:
			direction = left;
			return true;
		break;
		case SDLK_ESCAPE:
			this->close();
			return true;
		}
	}
	if(e.type == SDL_KEYUP)
	{
		switch(e.key.keysym.sym)
		{
		case SDLK_UP:
		case SDLK_DOWN:
		case SDLK_RIGHT:
		case SDLK_LEFT:
		case SDLK_ESCAPE:
			direction = none;
		return true;
		}
	}
}

void MovingRectangle::draw(int x , int y)
{
	switch(direction)
	{
	case up:
		this->y-=1;
		break;
	case down:
		this->y+=1;
		break;
	case left:
		this->x-=1;
		break;
	case right:
		this->x+=1;
		break;
	}
	Rectangle::draw(x,y);
}

MovingRectangle::~MovingRectangle(void)
{
}
