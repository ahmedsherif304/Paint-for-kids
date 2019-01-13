#ifndef EXIT_ACTION_H
#define EXIT_ACTION_H
#include "Action.h"
#include "SaveAction.h"

class ExitAction:public Action 
{
	SaveAction * S;

public:
	ExitAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	
};

#endif