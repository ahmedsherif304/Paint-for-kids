#include"Actions\Action.h"
#include "ApplicationManager.h"
#include"GUI\Input.h"
#include "GUI\Output.h"

#pragma once
class DrawColor:public Action
{
public:
	DrawColor(ApplicationManager*);
	void ReadActionParameters() ;
	void Execute() ;
	
};

