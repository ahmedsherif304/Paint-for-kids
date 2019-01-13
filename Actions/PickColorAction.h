#include "Action.h"
#include "DeleteAction.h"
#pragma once
class PickColorAction:public Action
{
	int RCount,WCount,BlueCounter, GreenCounter,WhiteCounter,BlackCounter,RedCounter,BKGCcounter;//the number of every color
	SelectAction *s;
	DeleteAction *d;
public:
	PickColorAction(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
};


