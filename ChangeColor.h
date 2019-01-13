#include"Actions\Action.h"
#include "ApplicationManager.h"
#include"GUI\Input.h"
#include "GUI\Output.h"

#pragma once
class ChangeColor:public Action
{
public:
	ChangeColor(ApplicationManager*);
	void ReadActionParameters() ;
	void Execute() ;
	
};

