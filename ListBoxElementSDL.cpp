#include "ListBoxElementSDL.h"
#include "ListBox.h"
#include "SDL_ttf.h"
#include "FontFactory.h"

ListBoxElementSDL::ListBoxElementSDL(int width)
{
	init(width);
}

ListBoxElementSDL::ListBoxElementSDL()
{
	init(100);
}

void ListBoxElementSDL::init(int width)
{
this->w = width;
	this->h = 12;
	this->x = 0;
	this->y = 0;
	this->cutSize = 0;
	this->dir = down;
	SDL_Color white, black, blue;
	white.r = 255; white.g = 255; white.b = 255;
	black.r = 0; black.g = 0; black.b = 0;
	blue.r = 70; blue.g = 130; blue.b = 180;
	this->normalColor = ColorSet(white, black);
	this->selectedColor = ColorSet(blue, black);
	this->operator+=(*(new Delegate(this)));
}

void ListBoxElementSDL::draw(int x, int y)
{
	DrawableSDL::draw(x,y);
	SDL_Rect rect;
	ColorSet currentColor;
	SDL_Surface *workingSurface = SDL_CreateRGBSurface(SDL_SWSURFACE,w,h,32,0,0,0,0);
	if(this->selected)
		currentColor = this->selectedColor;
	else
		currentColor = this->normalColor;
	rect.h = h;
	rect.w = w;
	rect.x = 0;
	rect.y = 0;
	SDL_FillRect(workingSurface, &rect, SDL_MapRGB(surface->format,
		currentColor.backgroundColor.r, currentColor.backgroundColor.g, currentColor.backgroundColor.b));

	if(this->text != "")
	{
		TTF_Font* font = FontFactory::getFont("simplePix");
		SDL_Surface* newSurface;
	
		newSurface = TTF_RenderText_Solid(font, text, currentColor.frontColor); 
		SDL_Rect cuts;
		//cuts.h = h; cuts.w = w;
		cuts.x = 0 ; cuts.y = 0;
		SDL_BlitSurface(newSurface, NULL, workingSurface, &cuts);
		SDL_FreeSurface(newSurface);
	}

	rect.x = real_x;
	rect.y = real_y;

	SDL_Rect cutting;
	cutting.x=0; cutting.y = 0; cutting.w=w; cutting.h = h;
	if(cutSize != 0)
	{
		if(dir == up)
		{
			cutting.y=cutSize;
		}
		else
		{
			cutting.h= cutting.h - cutSize;
		}
	}

	SDL_BlitSurface(workingSurface, &cutting, surface, &rect);
	SDL_FreeSurface(workingSurface);
}

void ListBoxElementSDL::cut(int px, Direction dir)
{
	this->cutSize = px;
	this->dir = dir;
}

bool ListBoxElementSDL::onClick(SDL_Event e, void* sender)
{
	this->setSelection(!selected);
	return true;
}

bool ListBoxElementSDL::spreadEvent(SDL_Event e)
{
	int y=this->y, h = this->h;
	if(cutSize)
	{
		if(dir == up)
			this->y = this->y + cutSize;
		else
			this->h = this->h - cutSize;
	}
	bool value =  DrawableSDL::spreadEvent(e);
	this->y = y;
	this->h = h;
	return value;
}

ListBoxElementSDL::~ListBoxElementSDL(void)
{
}
