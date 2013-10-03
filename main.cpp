#include "SDL.h"
#include "Drawable.h"
#include "DrawableSDL.h"
#include "Rectangle.h"
#include "Container.h"
#include "SDL_ttf.h"
#include "MovingRectangle.h"
#include "FramedRect.h"
#include "Button.h"
#include "FontFactory.h"
#include "SimpleScrollBar.h"
#include "ListBoxSDL.h"
#include "ListBoxElementSDL.h"
SDL_Surface *ekran;

int FPS = 50;


class smth : public EventDelegate
{
protected:
	bool change;
public:
	bool onClick(SDL_Event usedEvent, void* sender)
	{
		if(change) change = false;
		else change = true;
		Button* s = (Button*)sender;
		if(change)
		s->setBorderSize(100);
		else
			s->setBorderSize(1);
		return true;
	}
	bool mouseUp(SDL_Event usedEvent, void* sender) {return false;}
	bool keyDown(SDL_Event usedEvent, void* sender) {return false;}
	bool keyUp(SDL_Event usedEvent, void* sender)	{return false;}
};


int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
		
	ekran = SDL_SetVideoMode( 800, 600, 32, SDL_SWSURFACE );
	DrawableSDL::surface = ekran;
    SDL_Flip( ekran );
	SDL_CDOpen(0);
	ekran->pixels;
	SDL_Event e;
	int frame_time;
	SDL_PollEvent(&e);

	FontFactory::initializeFont("simplePix", "pixelart.ttf", 10);

	SDL_Rect rect;
	rect.x=100;
	rect.y=10;
	rect.w=100;
	rect.h=100;

	TTF_Init();

	Rectangle object1;
	object1.setColor(0xff, 0xff, 0xff);
	
	Rectangle object2;
	object2.setColor(0xf1, 0x00, 0xda);
	object2.setX(50);

	object1.setX(10);

	Container helping(100,30);
	//helping.add(&object1);

	Container root(10,10);

	SimpleScrollBar scroll(100, 100, 10, 150, 0, 1000, Orientation::horizontal);
	SimpleScrollBar scroll2(100, 85, 10, 150, 0, 1000, Orientation::horizontal);
	root.add(&scroll);
	Button ok(100, 100, 60, 20, "Here i am");
	ok.setBorderSize(2);
	ok.setBackground(255,225,255);
	ok.setBorderColor(10,100,10);
	ok.setFontName("simplePix");
	smth e_inst;
	ok+= *(new Delegate(&e_inst));

	Button ok2(200, 200, 80, 20, "I am not here");
	ok2.setBorderSize(2);
	ok2.setBackground(255,225,255);
	ok2.setBorderColor(10,100,10);
	ok2.setFontName("simplePix");
	root.add(&ok);
	root.add(&scroll2);
	root.add(&ok2);
	//ok.setEnable(false);

	ListBoxElementSDL el(50);
	el.setText("hello");
	el.setSelection(false);
	el.cut(4, down);
	ListBoxElementSDL el1(50);
	el1.setText("welcome");
	el1.setSelection(false);
	ListBoxElementSDL el2(50);
	el2.setText("hejo");
	el2.setSelection(false);
	ListBoxElementSDL el3(50);
	el3.setText("hejo2");
	ListBoxElementSDL el4(50);
	el4.setText("hejo1");
	ListBoxElementSDL el5(50);
	el5.setText("hejo3");
	ListBoxElementSDL el6(50);
	el6.setText("Witam");
	ListBoxElementSDL el7(50);
	el7.setText("Witam");

	ListBoxSDL list(500, 200, 100, 50, 2);
	list.add(&el);
	list.add(&el1);
	list.add(&el2);
	list.add(&el3);
	list.add(&el4);
	list.add(&el5);
	list.add(&el6);
	list.add(&el7);
	root.add(&list);
	MovingRectangle movrect;
	MovingRectangle movrect2;
	movrect2.setColor(0x43, 0x52, 0xFF);

	//root.add(&movrect);
	//root.add(&movrect2);
	Uint32 color = SDL_MapRGB(ekran->format, 0xff, 0xff, 0xff);
	Uint32 color2 = SDL_MapRGB(ekran->format, 0x00, 0xff, 0xff);
	short int r=0,g=0,b=0;
	while(true)
	{
		frame_time = SDL_GetTicks();
		ok.setX(scroll.getValue());
		ok.setY(scroll2.getValue());
		SDL_FillRect(ekran, &(ekran->clip_rect), color2);
		root.draw(0,0);

		if(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				SDL_Quit();
				return 0;
			}
			root.spreadEvent(e);
		}
		SDL_Flip(ekran);
		if((SDL_GetTicks() - frame_time) < 1000/FPS)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - frame_time));

	}


	return 0;
}