#include "ListBoxComboElement.h"


ListBoxComboElement::ListBoxComboElement(void)
{
	this->selectedColor = normalColor;
}

ListBoxComboElement::ListBoxComboElement(int size)
{
	this->selectedColor = normalColor;
}

ListBoxComboElement::ListBoxComboElement(int size, char* name, void* value)
{
	text = name;
	setValue(value);
}

ListBoxComboElement::~ListBoxComboElement(void)
{
}
