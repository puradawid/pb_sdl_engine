#pragma once
#include "Drawable.h"
enum Orientation{
	vertical,
	horizontal
};

/**
	Scrollbar interface to implementattion.
*/
class ScrollBarInterface
{
public:
	ScrollBarInterface(void);
	
	//sets the sizes of scrollbar
	virtual	void	setSizes(int width, int height) = 0;
	//returns width of scrollbar
	virtual	int		getWidth() = 0;

	virtual	int		getHeight() = 0;

	virtual	double	getValue() = 0;

	virtual void	setBounds(int a, int b) = 0;
	
	virtual void	setOrientation(Orientation orientation) = 0;
	
	virtual void	setUppBtt(Drawable &uppbtt) = 0;

	virtual void	setDownBtt(Drawable &downbtt) = 0;

	virtual void	setScroll(Drawable &scroll) = 0;

	virtual void	setBar(Drawable &bar) = 0;
	
	~ScrollBarInterface(void);
};

