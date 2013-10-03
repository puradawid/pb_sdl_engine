#pragma once
#include "ListBox.h"
#include "ComboBoxItem.h"
#include <vector>

[event_receiver(native)]
class ComboBox
{
protected:
	ComboBoxItem* current;
	std::vector<ComboBoxItem*> elements;
public:
	ComboBox();
	void add(ComboBoxItem* el);
	void select(ComboBoxItem* el);
	ComboBoxItem* getSelected();
};