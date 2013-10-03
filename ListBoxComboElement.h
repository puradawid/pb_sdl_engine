#pragma once
#include "listboxelementSDL.h"
class ListBoxComboElement :
	public ListBoxElementSDL
{
public:
	ListBoxComboElement(void);
	ListBoxComboElement(int size);
	ListBoxComboElement(int size, char* name, void* value);
	~ListBoxComboElement(void);
};

