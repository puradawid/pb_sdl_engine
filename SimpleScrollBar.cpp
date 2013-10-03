#include "SimpleScrollBar.h"
#include "Button.h"
#include "FramedRect.h"
SimpleScrollBar::SimpleScrollBar()
{
	this->bar = new FramedRect() ;
	this->upBtt = new Button();
	this->scroll = new Button();
	this->downBtt = new Button();
	this->setOrientation(vertical);
	this->setSizes(15, 100);
	this->setBounds(0,10);
	this->setBar(*bar);
	this->setUppBtt(*upBtt);
	this->setDownBtt(*downBtt);
	this->setScroll(*scroll);
	((Button*)scroll)->setBorderSize(1);
	((Button*)scroll)->setBorderColor(0,0,0);
	this->setX(0);
	this->setY(0);
	((Button*)upBtt)->setBackground(177,177,177);
	((Button*)downBtt)->setBackground(177,177,177);
	((FramedRect*)bar)->setBackground(224,224,224);
}

SimpleScrollBar::SimpleScrollBar(int x, int y, int width, int height, int a, int b, Orientation orientation)
{
	this->bar = new FramedRect() ;
	this->upBtt = new Button();
	this->scroll = new Button();
	this->downBtt = new Button();
	this->setOrientation(orientation);
	this->setSizes(width, height);
	this->setBounds(a,b);
	this->setBar(*bar);
	this->setUppBtt(*upBtt);
	this->setDownBtt(*downBtt);
	this->setScroll(*scroll);
	((Button*)scroll)->setBorderSize(1);
	((Button*)scroll)->setBorderColor(0,0,0);
	this->setX(x);
	this->setY(y);
	((Button*)upBtt)->setBackground(177,177,177);
	((Button*)downBtt)->setBackground(177,177,177);
	((FramedRect*)bar)->setBackground(224,224,224);
}


SimpleScrollBar::~SimpleScrollBar(void)
{
}
