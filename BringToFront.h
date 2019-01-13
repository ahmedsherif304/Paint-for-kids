#pragma once
#include "Actions\Action.h"
class BringToFront:public Action
{
public:

	BringToFront(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

