#pragma once
#include "Actions\Action.h"
#include "Actions\DeleteAction.h"
class PasteAction : public Action
{
private:
	int Switch;
	DeleteAction *d;
public:

	PasteAction(ApplicationManager *pApp,int);
	
virtual void ReadActionParameters();
virtual void Execute();


	~PasteAction();
};

