#include "Action.h"

#include"SelectAction.h"
#pragma once
class DeleteAction:public Action
{ 
public:
	DeleteAction(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	~DeleteAction(void);
};

