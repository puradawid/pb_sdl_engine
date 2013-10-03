#pragma once
#include <vector>
#include "SDL.h"
#include <stdlib.h>
#include "Drawable.h"
/*
	It is really important define of delegating function
*/



class EventDelegate
{
public:
	virtual bool onClick(SDL_Event usedEvent, void* sender)		{return false;}
	virtual bool mouseDown(SDL_Event usedEvent, void* sender)	{return false;}
	virtual bool mouseUp(SDL_Event usedEvent, void* sender)		{return false;}
	virtual bool keyDown(SDL_Event usedEvent, void* sender)		{return false;}
	virtual bool keyUp(SDL_Event usedEvent, void* sender)		{return false;}
	virtual bool timeUp(SDL_Event usedEvent, void* sender)		{return false;}
	virtual bool mouseMove(SDL_Event usedEvent, void* sender)		{return false;}
};

typedef bool (EventDelegate::*EventMethod)(SDL_Event usedEvent, void* sender);

class Delegate
{
	EventDelegate	*object;
	EventMethod		method;
public:
	Delegate(EventDelegate *object, EventMethod method)
	{ this->object = object, this->method = method;}
	Delegate(EventDelegate *object)
	{ this->object = object, this->method = NULL;}
	Delegate() { this->object = NULL, this->method = NULL;}
	EventMethod getMethod() { return method;}
	EventDelegate* getObject() { return object;}
};

enum EventType
{
	onMouseDown,
	onMouseUp,
	onMouseClicked,
	onKeyDown,
	onKeyUp,
	onTimeInterrupt
};

class EventHandler
{
protected:
	std::vector<Delegate>	handlers;
	Delegate mouseClicked;
	bool pressed;
public:
	EventHandler(void);
	bool spreadEvent(SDL_Event);
	void operator+=(Delegate);
	~EventHandler(void);
};

