#ifndef DrawBlue_H
#define DrawBlue_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class DrawBlue: public Action
{

public:
	DrawBlue(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif