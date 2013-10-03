#pragma once
#include "drawablesdl.h"
#include "SDL.h"

class FramedRect :
	public DrawableSDL
{
protected:
	int border;
	Uint32 backgroundColor, borderColor;
	Uint32 convertColor(char, char, char);
public:
	FramedRect(void);
	FramedRect(int, int, int, int, int);
	
	void setBackground(char, char, char);
	void setBorderColor(char, char, char);
	void setBorderSize(int size);

	void draw(int, int);

	~FramedRect(void);
};

