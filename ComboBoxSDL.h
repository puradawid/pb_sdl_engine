#pragma once
#include "drawablesdl.h"
#include "ListBoxSDL.h"
#include "Button.h"
#include "ListBoxComboElement.h"
#include "ComboBox.h"
class ComboBoxSDL :
	public DrawableSDL, public ComboBox
{
protected:
	Button *btt;
	ListBoxSDL *list;
	bool showed;
public:
	ComboBoxSDL(void);
	void add(char *name, void* value);
	~ComboBoxSDL(void);
};

