#pragma once
#include "listboxelement.h"
#include "DrawableSDL.h"
#include "SDL.h"
enum Direction
{
	up,
	down
};

typedef struct ColorSet {
	SDL_Color backgroundColor;
	SDL_Color frontColor;
	ColorSet() { backgroundColor = SDL_Color(); frontColor = SDL_Color();}
	ColorSet(SDL_Color back, SDL_Color front) { backgroundColor = back; frontColor = front;}
} ColorSet;

class ListBoxElementSDL :
	public ListBoxElement, public DrawableSDL, public EventDelegate
{
protected:
	char* fontName;
	ColorSet normalColor, selectedColor;
	int cutSize; Direction dir;
	void init(int width);
public:
	ListBoxElementSDL(int width);
	ListBoxElementSDL();
	void setFontName(char* f);
	void draw(int x, int y);
	bool onClick(SDL_Event e, void* sender);
	void cut(int px, Direction dir);
	bool spreadEvent(SDL_Event e);
	~ListBoxElementSDL(void);
};

