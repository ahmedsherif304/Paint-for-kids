#pragma once
#include "Actions\Action.h"

class CutAction:public Action
{
	int S;
color OldColor;
public:
	
	CutAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	color GetOldColor();
	~CutAction(void);
};

