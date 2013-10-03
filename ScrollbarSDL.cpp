#include "ScrollbarSDL.h"
#include "Drawable.h"
#include "DrawableSDL.h"
#include "EventHandler.h"
ScrollbarSDL::ScrollbarSDL(void)
{
	scroll = NULL;
	downBtt = NULL;
	upBtt = NULL;
	bar = NULL;
	setOrientation(horizontal);
	setSizes(10, 100);
	setX(0);
	setY(0);
	this->scrollPos = 0;
	move = 0;
}

void ScrollbarSDL::setSizes(int width, int height)
{
	this->width = width;
	this->height = height;
}

int ScrollbarSDL::getWidth() {return this->width;}

int	ScrollbarSDL::getHeight() {return this->height;}

double ScrollbarSDL::getValue()
{
	return value = a + scrollPos * vop;
}

void ScrollbarSDL::setBounds(int a, int b)
{
	this->a = a;
	this->b = b;
	this->vop = (b - a) / ((double)height - 3*width );
}
	
void ScrollbarSDL::setOrientation(Orientation orientation)
{
	this->orientation = orientation;
}
	
void ScrollbarSDL::setUppBtt(Drawable &uppbtt)
{
	UpButtonActions *s = new UpButtonActions(this);
	Delegate d((EventDelegate*)s);
	this->upBtt = dynamic_cast<DrawableSDL *>(&uppbtt);
	upBtt->setH(this->width);
	upBtt->setW(this->width);
	this->upBtt->setX(0);
	this->upBtt->setY(0);
	(*upBtt)+=d;
}

void ScrollbarSDL::setDownBtt(Drawable &downbtt)
{
	DownButtonActions *s = new DownButtonActions(this);
	Delegate d((EventDelegate*)s);
	this->downBtt = dynamic_cast<DrawableSDL *>(&downbtt);
	downBtt->setH(this->width);
	downBtt->setW(this->width);
	this->downBtt->setX(0);
	this->downBtt->setY(0);
	(*downBtt)+=d;
}

void ScrollbarSDL::setScroll(Drawable &scroll)
{
	ScrollActions *s = new ScrollActions(this);
	Delegate d((EventDelegate*)s);
	this->scroll = dynamic_cast<DrawableSDL *>(&scroll);
	this->scroll->setX(0);
	this->scroll->setY(0);
	this->scroll->setW(this->width);
	this->scroll->setH(this->width);
	(*this->scroll)+=d;

}

void ScrollbarSDL::setBar(Drawable &bar)
{
	BarActions *s = new BarActions(this);
	Delegate d((EventDelegate*)s);
	this->bar = dynamic_cast<DrawableSDL *>(&bar);
	this->bar->setX(0);
	this->bar->setY(0);
	if(orientation == Orientation::vertical)
	{
		this->bar->setH(this->height - 2 * this->width);
		this->bar->setW(this->width);
	} else
	{
		this->bar->setH(this->width);
		this->bar->setW(this->height - 2 * this->width);
	}
	(*this->bar)+=d;
}

void ScrollbarSDL::draw(int x, int y)
{
	if(height < 3*width) return;
	DrawableSDL::draw(x, y);
	if( move && scrollPos + move >= 0 && scrollPos + move <= height - 3*width)
	{
		scrollPos += move;
	}
	x = x + this->x;
	y = y + this->y;
	if(orientation == Orientation::horizontal)
	{
		bar->draw(x + width, y);
		
		upBtt->draw(x, y);
		downBtt->draw(x + height - width, y);
		scroll->draw(x + width + scrollPos, y);
	} else
	if(orientation == Orientation::vertical)
	{
		bar->draw(x, y + width);
		
		upBtt->draw(x, y);
		downBtt->draw(x, y + height - width);
		scroll->draw(x, y + width + scrollPos);
	}
}

bool ScrollbarSDL::spreadEvent(SDL_Event e)
{
	if(scroll->spreadEvent(e))
		return true;
	if(bar->spreadEvent(e))
		return true;
	if(downBtt->spreadEvent(e))
		return true;
	if(upBtt->spreadEvent(e))
		return true;
	return false;

}

ScrollbarSDL::~ScrollbarSDL(void)
{
	/*
	if(bar)
		free(bar);
	if(downBtt)
		free(downBtt);
	if(scroll)*
		free(scroll);
	if(upBtt)
		free(upBtt); */
}


bool ScrollbarSDL::DownButtonActions::onClick(SDL_Event usedEvent, void *obj)
{
	if(there->scrollPos < there->height - 3 * there->width)
	there->scrollPos++;
	return true;
}

bool ScrollbarSDL::UpButtonActions::onClick(SDL_Event usedEvent, void *obj)
{
	if(there->scrollPos > 0)
		there->scrollPos--;
	return true;
}

bool ScrollbarSDL::ScrollActions::mouseDown(SDL_Event usedEvent, void *obj)
{
	scrollMoving = true;
	if(there->orientation == Orientation::horizontal)
		lastPos = usedEvent.button.x;
	else
		lastPos = usedEvent.button.y;
	return true;
}
bool ScrollbarSDL::ScrollActions::mouseUp(SDL_Event usedEvent, void *obj)
{
	scrollMoving = false;
	return true;
}

bool ScrollbarSDL::ScrollActions::mouseMove(SDL_Event usedEvent, void *obj)
{
	if(!scrollMoving) return false;

	switch(there->orientation)
	{
	case Orientation::horizontal:
		if(usedEvent.motion.xrel + there->scrollPos >= 0 && usedEvent.motion.xrel + there->scrollPos <= there->height - 3 * there->width)
			there->scrollPos += usedEvent.motion.xrel;
	case Orientation::vertical:
		if(usedEvent.motion.yrel + there->scrollPos >= 0 && usedEvent.motion.yrel + there->scrollPos <= there->height - 3 * there->width)
			there->scrollPos += usedEvent.motion.yrel;
		break;
	}
	there->getValue();
	return true;
}

void ScrollbarSDL::moveByVect(int x, int y)
{
	int pos, real_x = this->real_x + width, real_y = this->real_y + width;
	switch(orientation)
	{
	case Orientation::horizontal:
		if(x >= real_x && x <= real_x + height - 3* width)
			scrollPos = x - real_x;
		else
			scrollPos = height - 3*width;
		break;
	case Orientation::vertical:
		if(y >= real_y && y <= real_y + height - 3* width)
			scrollPos = y - real_y;
		else
			scrollPos = height - 3*width;
		break;
	}
}

bool ScrollbarSDL::BarActions::onClick(SDL_Event e, void* sender)
{
	there->moveByVect(e.button.x, e.button.y);
	return true;
}

bool ScrollbarSDL::DownButtonActions::mouseDown(SDL_Event e, void* sender)
{
	there->move = 1;
	return true;
}
bool ScrollbarSDL::DownButtonActions::mouseUp(SDL_Event e, void* sender)
{
	there->move = 0;
	return true;
}

bool ScrollbarSDL::UpButtonActions::mouseDown(SDL_Event e, void* sender)
{
	there->move = -1;
	return true;
}
bool ScrollbarSDL::UpButtonActions::mouseUp(SDL_Event e, void* sender)
{
	there->move = 0;
	return true;
}

void ScrollbarSDL::setHeight(int height)
{
	this->height = height;
}
