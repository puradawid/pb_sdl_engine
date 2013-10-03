#pragma once
#include "Drawable.h"
#include "DrawableSDL.h"
#include "ScrollBarInterface.h"



class ScrollbarSDL : public ScrollBarInterface, public DrawableSDL
{
protected:
	int width, height, a, b, scrollPos;
	double vop;
	Orientation orientation;
	double value;
	int move;
	DrawableSDL *upBtt, *downBtt, *scroll, *bar;
	void moveByVect(int x, int y);
	class DownButtonActions 
		: public EventDelegate
	{
	protected:
		ScrollbarSDL* there;
	public:
		bool	onClick(SDL_Event e, void *sender);
		bool	mouseUp(SDL_Event e, void *sender);
		bool	mouseDown(SDL_Event e, void *sender);
		DownButtonActions(ScrollbarSDL *there) {this->there = there;};
	};
	class BarActions 
		: public EventDelegate
	{
	protected:
		ScrollbarSDL* there;
	public:
		bool	onClick(SDL_Event e, void *sender);
		BarActions(ScrollbarSDL *there) {this->there = there;};
	};
	class UpButtonActions
		: public EventDelegate
	{
	protected:
		ScrollbarSDL* there;
	public:
		bool	onClick(SDL_Event e, void *sender);
		bool	mouseUp(SDL_Event e, void *sender);
		bool	mouseDown(SDL_Event e, void *sender);
		UpButtonActions(ScrollbarSDL * there) {this->there = there;};
	};
	class ScrollActions
		: public EventDelegate
	{
	protected:
		ScrollbarSDL* there;
		bool scrollMoving;
		int lastPos;
	public:
		bool	mouseDown(SDL_Event e, void *sender);
		bool	mouseUp(SDL_Event e, void *sender);
		bool	mouseMove(SDL_Event e, void *sender);
		ScrollActions(ScrollbarSDL * there) {this->there = there; scrollMoving = false;};
	};
public:
	ScrollbarSDL(void);
	
	void	setSizes(int width, int height);
	
	int		getWidth();

	int		getHeight();

	double	getValue();

	void	setBounds(int a, int b);
	
	void	setOrientation(Orientation orientation);
	
	void	setUppBtt(Drawable &uppbtt);

	void	setDownBtt(Drawable &downbtt);

	void	setScroll(Drawable &scroll);

	void	setBar(Drawable &bar);

	void	setHeight(int height);

	void	draw(int x, int y);
	
	bool	spreadEvent(SDL_Event e);

	~ScrollbarSDL(void);
};

