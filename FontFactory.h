#pragma once
#include "SDL_ttf.h"
#include <vector>
#include <stdlib.h>
class FontFactory
{
protected:
	static std::vector<std::pair<char*, TTF_Font*>> fonts; 
public:
	FontFactory();
	static void initializeFont(char*, char*, int);
	static TTF_Font* getFont(char*);
	~FontFactory(void);
};

