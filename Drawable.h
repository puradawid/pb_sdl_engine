#pragma once
#include <vector>
using namespace std;

class Drawable
{
private:
	vector<Drawable *> static drawableCollection;
protected:
	int x,y,w,h;
public:
	Drawable(int x, int y, int w, int h);
	Drawable(void);
	virtual void draw(int,int){};
	~Drawable(void);

	//setters & getters

	void setX(int);
	void setY(int);
	void setW(int);
	void setH(int);

	int getX();
	int getY();
	int getW();
	int getH();
};


