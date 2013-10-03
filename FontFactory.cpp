#include "FontFactory.h"
#include "SDL_ttf.h"

std::vector<std::pair<char*, TTF_Font*>> FontFactory::fonts; 

FontFactory::FontFactory(void)
{

}

void FontFactory::initializeFont(char* fontName, char* fontFile, int pxSize)
{
	int returned = TTF_Init();
	TTF_Font* font;
	std::pair<char*, TTF_Font*> fontPair;
	fontPair.first = fontName;
	font = TTF_OpenFont(fontFile, pxSize);
	fontPair.second = font;
	fonts.push_back(fontPair);
}

TTF_Font* FontFactory::getFont(char* fontName)
{
	std::vector<std::pair<char*, TTF_Font*>>::iterator it = fonts.begin();
	do
	{
		if((*it).first == fontName)
			return (*it).second;
		it++;
	} while(it != fonts.end());
	return NULL;
}
FontFactory::~FontFactory(void)
{
	for(std::vector<std::pair<char*, TTF_Font*>>::iterator it = fonts.begin(); it<fonts.end(); it++)
	{
		TTF_CloseFont((*it).second);
	}
}
