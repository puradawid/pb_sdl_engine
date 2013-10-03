#include "Drawable.h"


Drawable::Drawable(void)
{
	Drawable::drawableCollection.push_back(this);
}

Drawable::Drawable(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

vector<Drawable*>::iterator findElement(vector<Drawable*>* vect, Drawable* pointer)
{
	vector<Drawable*>::iterator iter = (*vect).begin();
	while(iter != (*vect).end())
	{
		if(*iter == pointer) return iter;
		iter++;	
	}
	return(*vect).begin();
}

Drawable::~Drawable(void)
{
	Drawable::drawableCollection.erase(findElement(&Drawable::drawableCollection, this));
}

void Drawable::setX(int x){this->x = x;}
void Drawable::setY(int y){this->y = y;}
void Drawable::setH(int h){this->h = h;}
void Drawable::setW(int w){this->w = w;}

int Drawable::getX(){return this->x;}
int Drawable::getY(){return this->y;}
int Drawable::getH(){return this->h;}
int Drawable::getW(){return this->w;}


vector<Drawable *> Drawable::drawableCollection;