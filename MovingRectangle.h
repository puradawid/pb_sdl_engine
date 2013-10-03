#pragma once
#include "rectangle.h"
class MovingRectangle :
	public Rectangle
{
protected:
	enum DIR {left, right, up, down, none} direction;
public:
	MovingRectangle(void);
	
	void draw(int, int);
	bool spreadEvent(SDL_Event);

	~MovingRectangle(void);
};

