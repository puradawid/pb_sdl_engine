#include "EventHandler.h"
#include <vector>
EventHandler::EventHandler(void)
{
}

void EventHandler::operator+=(Delegate p)
{
	///*switch(p.first)
	//{
	//case EventType::onKeyDown:
	//	keyDownPtr.push_back(p.second);	
	//break;
	//case EventType::onKeyUp:
	//	keyUpPtr.push_back(p.second);
	//break;
	//case EventType::onMouseDown:
	//	mouseDownPtr.push_back(p.second);
	//break;
	//case EventType::onMouseUp:
	//	mouseUpPtr.push_back(p.second);
	//break;
	//case EventType::onTimeInterrupt:
	//	timeUpPtr.push_back(p.second);
	//break;
	//case EventType::onMouseClicked:
	//	this->mouseClicked = p.second;
	//break;*/
	//}
	this->handlers.push_back(p);
}


bool EventHandler::spreadEvent(SDL_Event e)
{
	return false;
}

EventHandler::~EventHandler(void)
{
}
