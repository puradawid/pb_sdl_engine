#include "Button.h"
#include "SDL_ttf.h"
#include "FontFactory.h"

Button::Button(void)
{
	setX(0);
	setY(0);
	setW(1);
	setH(1);
	SDL_Color fontC = {255,255,255};
	SDL_Color black = {0,0,0};
	SDL_Color some = {32, 43, 234};
	this->fontClickedColor = fontC;
	this->fontColor = black;
	this->frontClicked = some;
	front_text = "";
	pressed = false;
	enabled = true;
}

Button::Button(int x, int y, int w, int h, char* frontText)
{
	setX(x);
	setY(y);
	setW(w);
	setH(h);
	SDL_Color fontC = {255,255,255};
	SDL_Color black = {0,0,0};
	SDL_Color some = {32, 43, 234};
	this->fontClickedColor = fontC;
	this->fontColor = black;
	this->frontClicked = some;
	front_text = frontText;
	pressed = false;
	enabled = true;
}

void Button::draw(int x, int y)
{
	SDL_Color textColor;
	Uint32 temp = this->backgroundColor;
	if(pressed && enabled)
	{
		textColor = this->fontClickedColor;
		this->backgroundColor = SDL_MapRGB(surface->format, frontClicked.r, frontClicked.g, frontClicked.b);
	}
	else
	{
		textColor = this->fontColor;
	}
	FramedRect::draw(x,y);
	if(front_text != "")
	{
		TTF_Font* font = FontFactory::getFont(fontName);
		SDL_Surface* newSurface;
	
		
		newSurface = TTF_RenderText_Solid(font, this->front_text, textColor); 
		SDL_Rect cuts;
		cuts.h = h; cuts.w = w;
		cuts.x = this->x + x + w/2 - newSurface->w / 2; cuts.y = this->y + y + h/2 - newSurface->h/2;
		SDL_BlitSurface(newSurface, NULL, surface, &cuts);
		SDL_FreeSurface(newSurface);
	}
	this->backgroundColor = temp;
}

void Button::setFontName(char* fontName)
{
	this->fontName = fontName;
}

void Button::setEnable(bool enabled)
{
	this->enabled = enabled;
}

bool Button::isEnabled()
{
	return this->enabled;
}

bool Button::spreadEvent(SDL_Event e)
{
	if(enabled) return DrawableSDL::spreadEvent(e);
	return false;
}

Button::~Button(void)
{
}
