#pragma once
#include "drawable.h"
#include "SDL.h"
#include "EventHandler.h"
class DrawableSDL :
	public Drawable,
	public EventHandler
{
protected:
	bool isContain(int x, int y);
	int real_x; int real_y;
	void moveByVect(int x, int y);
public:
	Drawable* parent;
	static SDL_Surface *surface;
	virtual void draw(int x, int y);
	DrawableSDL(void);
	~DrawableSDL(void);
	virtual bool spreadEvent(SDL_Event);
	void close();
};

