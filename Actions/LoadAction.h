#pragma once
#include "Action.h"
#include <string>

class LoadAction: public Action
{
	string File_Name;
public:
	LoadAction(ApplicationManager *pApp);
	LoadAction(ApplicationManager *pApp,string);
	void ReadActionParameters();
	void Execute();
	~LoadAction();
};

