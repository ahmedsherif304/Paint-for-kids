#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "Actions\DeleteAction.h"
#include "Figures\CFigure.h"
#pragma once
class Resize :public Action
{
	DeleteAction *d;
	CFigure* c;
public:
	Resize(ApplicationManager*);
	void ReadActionParameters();
	void Execute(); 
	~Resize(void);
};

