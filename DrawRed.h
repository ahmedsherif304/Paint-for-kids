#ifndef DrawRed_H
#define DrawRed_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class DrawRed: public Action
{

public:
	DrawRed(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif