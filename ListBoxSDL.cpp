#include "ListBoxSDL.h"
#include "ListBoxElementSDL.h"
#include "FramedRect.h"
ListBoxSDL::ListBoxSDL(int x, int y, int w, int h, int selectLimit)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->scroll = new SimpleScrollBar(0, 0, 15, h, 0, 100, vertical);
	this->itemToSelect = selectLimit;
}

void ListBoxSDL::draw(int x, int y)
{
	DrawableSDL::draw(x, y);
	
	FramedRect rect;
	rect.setX(real_x); rect.setY(real_y);
	rect.setBorderSize(0);
	rect.setW(w);
	rect.setH(h);
	rect.setBackground(255,255,255);
	rect.draw(0,0);

	int start = scroll->getValue() / 12;

	int window = h / 12;
	int move = (int)(scroll->getValue()) % 12;
	int order = 0;
	((ListBoxElementSDL*)elements[start])->cut(move,up);
	((ListBoxElementSDL*)elements[start])->setW(this->w);
	((ListBoxElementSDL*)elements[start])->draw(this->x + x, this->y + y);
	
	for(int i=start + 1; i < elements.size() && i < window + start; i++)
	{
		((ListBoxElementSDL*)elements[i])->cut(0,up);
		((ListBoxElementSDL*)elements[i])->setW(this->w);
		((ListBoxElementSDL*)elements[i])->draw(this->x + x, this->y + y + (i - start) * 12 - move);
		order = i;
	}
	if(order + start - 1 < elements.size())
	{
		int cutting = h - (((window - 1) * 12) + (12 - move));
		((ListBoxElementSDL*)elements[order+1])->cut(12 - cutting , down);
		((ListBoxElementSDL*)elements[order+1])->setW(this->w);
		((ListBoxElementSDL*)elements[order+1])->draw(this->x + x, this->y + y + (12*(order - start) +(12 -move)));
	}
	this->scroll->draw(real_x + w, real_y);
}

bool ListBoxSDL::spreadEvent(SDL_Event e)
{
	for(int i=0; i < elements.size(); i++)
		((ListBoxElementSDL*)elements[i])->spreadEvent(e);
	scroll->spreadEvent(e);
	return false;
}

void ListBoxSDL::add(ListBoxElement *el)
{
	if(((elements.size() + 1) * 12) - this->h > 0)
		scroll->setBounds(0, ((elements.size() + 1)  * 12) - this->h);
	ListBox::add(el);
}

ListBoxSDL::~ListBoxSDL(void)
{
}
