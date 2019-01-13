#include"Action.h"
#include "LoadAction.h"
#pragma once
class switchToDrawAction:public Action
{
	LoadAction *l;
public:
	switchToDrawAction(ApplicationManager*);
	void ReadActionParameters() ;
	void Execute() ;
	~switchToDrawAction(void);
};

