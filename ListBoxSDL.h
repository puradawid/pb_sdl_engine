#pragma once
#include "listbox.h"
#include "EventHandler.h"
#include "SimpleScrollBar.h"
#include "DrawableSDL.h"
class ListBoxSDL :
	public ListBox, public DrawableSDL
{
protected:
	SimpleScrollBar* scroll;
public:
	ListBoxSDL(int x, int y, int w, int h, int selectLimit);
	void draw(int x, int y);
	bool spreadEvent(SDL_Event e);
	void add(ListBoxElement *el);
	~ListBoxSDL(void);
};

