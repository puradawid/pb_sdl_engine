#pragma once
#include "ListBoxElement.h"
#include <vector>

[event_receiver(native)]
class ListBox
{
protected:
	std::vector<ListBoxElement* > elements;
	int itemToSelect;
public:
	ListBox(void);
	void setItemsToSelect(int items);
	int getItemsToSelect();
	void add(ListBoxElement* e);
	void remove(ListBoxElement* e);
	std::vector<ListBoxElement *> getSelected();
	void select(ListBoxElement* e, bool value);
	~ListBox(void);
};

