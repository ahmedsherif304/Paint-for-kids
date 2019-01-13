#pragma once
#include "Action.h"
#include "..\\Figures/CFigure.h"
#include <string>

class SaveAction : public Action
{
private:
	string file_name;
public:
	SaveAction (ApplicationManager * pApp);
	SaveAction (ApplicationManager * pApp,string);
	void ReadActionParameters();
	void Execute();
	
};

