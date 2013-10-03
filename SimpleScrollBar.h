#pragma once
#include "ScrollBarSDL.h"
class SimpleScrollBar : public ScrollbarSDL
{
public:
	SimpleScrollBar(int x, int y, int width, int height, int a, int b, Orientation o);
	SimpleScrollBar();
	~SimpleScrollBar(void);
};

