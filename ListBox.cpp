#include "ListBox.h"
#include "ListBoxElement.h"
using namespace std;

ListBox::ListBox()
{
	itemToSelect = 1;
}

void ListBox::setItemsToSelect(int items)
{
	this->itemToSelect = items;
}

int ListBox::getItemsToSelect()
{
	return this->itemToSelect;
}

void ListBox::add(ListBoxElement* el)
{
	if(el == NULL) return;
	__hook(&ListBoxElement::selectionChanged, el, &ListBox::select);
	this->elements.push_back(el);
}

void ListBox::remove(ListBoxElement* el)
{
	for(int i=0; i<elements.size(); i++)
	{
		if(elements[i] == el)
			elements.erase(elements.begin() + i);
	}
}

vector<ListBoxElement*> ListBox::getSelected()
{
	vector<ListBoxElement*> selected;
	for(int i=0; i<elements.size(); i++)
	{
		if(elements[i]->isSelected())
			selected.push_back(elements[i]);
	}
	return selected;
}

void ListBox::select(ListBoxElement* e, bool value)
{
	vector<ListBoxElement*>s = getSelected();
	if(value)
	{
		if(s.size() == this->itemToSelect)
		{
			(*s.begin())->setSelection(false);
			s.erase(s.begin());
		}
	}
}

ListBox::~ListBox(void)
{

}