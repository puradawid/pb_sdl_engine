#include "ComboBoxSDL.h"


ComboBoxSDL::ComboBoxSDL(void)
{
	this->btt = new Button(0,0,12,12,"");
	this->list = new ListBoxSDL(x,y,w,100,1);
}


void ComboBoxSDL::add(char* name, void* value)
{
	this->elements.push_back(new ComboBoxItem(name));
	this->list->add(new ListBoxComboElement(this->w, name, value));
}

ComboBoxSDL::~ComboBoxSDL(void)
{
}
