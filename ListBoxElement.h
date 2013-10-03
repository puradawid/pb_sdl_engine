#pragma once
[event_source(native)]
class ListBoxElement
{
protected:
	void* obj;
	char* text;
	bool selected;
	void* boxParent;
public:
	ListBoxElement(void);
	void	setValue(void *obj);
	void	setText(char* text);
	char*	getText();
	void*	getObject();
	void* getParent();
	void	setParent(void* parent);
	bool	isSelected();
	__event void selectionChanged(ListBoxElement* el, bool val);
	void	setSelection(bool selection);
	~ListBoxElement(void);
};

