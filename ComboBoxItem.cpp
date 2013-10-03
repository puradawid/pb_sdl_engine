#include "ComboBoxItem.h"
#include <stdlib.h>

ComboBoxItem::ComboBoxItem(void)
{
	this->obj = NULL;
	this->text = "notext";
}

ComboBoxItem::ComboBoxItem(char *text)
{
	this->text = text;
	this->obj = NULL;
	this->selected = false;
}

char* ComboBoxItem::getText()
{
	return this->text;
}

void ComboBoxItem::setValue(void *val)
{
	this->obj = val;
}

void* ComboBoxItem::getObject()
{
	return this->obj;
}
void ComboBoxItem::setSelection()
{
	__raise selectionChanged(this);
}
ComboBoxItem::~ComboBoxItem(void)
{
}
