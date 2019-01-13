#include "Action.h"
#include "DeleteAction.h"
#include"..\Figures\CFigure.h"
#pragma once
class PickTypeAction:public Action
{
	int RCount,WCount,rectCounter,triCounter,lineCounter,ellipseCounter,rhombusCounter;
	SelectAction *s;
	DeleteAction *d;
public:
	PickTypeAction(ApplicationManager*);
	void ReadActionParameters();
	void Execute();

};

