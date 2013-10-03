#pragma once
#include "drawablesdl.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "FramedRect.h"

class Button :
	public FramedRect
{
protected:
	char* front_text;
	char* fontName;
	SDL_Color fontColor;
	SDL_Color frontClicked;
	SDL_Color fontClickedColor;
	bool enabled;
public:
	Button(void);
	/*virtual bool spreadEvent(SDL_Event);*/
	void draw(int, int);
	void setFontName(char*);
	void setFontColor(char r, char g, char b);
	void setFrontClicked(char r, char g, char b);
	void setFontClickedColor(char r, char g, char b);
	bool isEnabled();
	void setEnable(bool enable);
	bool spreadEvent(SDL_Event e); 
	Button(int x, int y, int w, int h, char* text); //x, y, w, h, text
	~Button(void);
};

