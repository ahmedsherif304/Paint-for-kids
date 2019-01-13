#pragma once
#include "Actions\Action.h"
class BringToBack:public Action
{
public:

	BringToBack(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

