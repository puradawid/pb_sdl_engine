#pragma once
#include "drawablesdl.h"
#include "EventHandler.h"
class Container :
	public DrawableSDL
{
protected:
	vector<DrawableSDL*> cont;
public:
	Container(void);
	Container(int, int);
	void add(DrawableSDL*);
	void remove(DrawableSDL*);
	void draw(int,int);
	bool spreadEvent(SDL_Event);
	~Container(void);
};

