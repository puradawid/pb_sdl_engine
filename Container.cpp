#include "Container.h"


Container::Container(void)
{
	setX(0);
	setY(0);
}

Container::Container(int x, int y)
{
	setX(x);
	setY(y);
}

void Container::draw(int x, int y)
{
	vector<DrawableSDL *>::iterator it = cont.begin();
	while(it != cont.end())
	{
		(*it)->draw(this->x + x, this->y + y);
		it++;
	}
}

void Container::remove(DrawableSDL* element)
{
	vector<DrawableSDL *>::iterator it = cont.begin();
	while(it != cont.cend())
	{
		if((*it) == element)
		{
			cont.erase(it);
			return;
		}
		it++;
	}
}

void Container::add(DrawableSDL* drawing)
{
	drawing->parent = this;
	cont.push_back(drawing);
}


Container::~Container(void)
{
	return;
	vector<DrawableSDL *>::iterator it = cont.begin();
	while(cont.size() > 0)
	{
		cont.erase(it);
		it++;
	}
}

bool Container::spreadEvent(SDL_Event e)
{
	for(int i = cont.size()-1; i>=0; i--)
		if(cont[i]->spreadEvent(e)) 
			return true;
	return false;
}
