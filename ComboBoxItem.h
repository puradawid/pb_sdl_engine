#pragma once
#include "listboxelement.h"
[event_source(native)]
class ComboBoxItem : ListBoxElement
{
public:
	ComboBoxItem();
	ComboBoxItem(char* name);
	void setValue(void *value);
	void *getObject();
	char* getText();
	__event void selectionChanged(ComboBoxItem* item);
	void setSelection();
	~ComboBoxItem(void);
};

