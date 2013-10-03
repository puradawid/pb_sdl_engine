#include "ListBoxElement.h"
ListBoxElement::ListBoxElement(void)
{
	this->obj = nullptr;
	this->text = nullptr;
	this->selected = false;
}

void* ListBoxElement::getObject()
{
	return this->obj;
}

void ListBoxElement::setValue(void* e)
{
	this->obj = e;
}

void ListBoxElement::setSelection(bool b)
{
	if(boxParent == 0x00)
		this->selected = b;
	else
	{
		__raise selectionChanged(this, b);
			this->selected = b;
	}
}

void ListBoxElement::setText(char* text)
{
	this->text = text;
}

char* ListBoxElement::getText()
{
	return this->text;
}

bool ListBoxElement::isSelected()
{
	return this->selected;
}

void ListBoxElement::setParent(void * parent)
{
	this->boxParent = parent;
}

void* ListBoxElement::getParent()
{
	return this->boxParent;
}

ListBoxElement::~ListBoxElement(void)
{

}
