#include "ComboBox.h"

ComboBox::ComboBox()
{
	this->current = NULL;
}

void ComboBox::add(ComboBoxItem *el)
{
	elements.push_back(el);
	__hook(&ComboBoxItem::selectionChanged, el, &ComboBox::select);
}

void ComboBox::select(ComboBoxItem *el)
{
	current = el;
}

ComboBoxItem* ComboBox::getSelected()
{
	return current;
}