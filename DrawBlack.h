#ifndef DrawBlack_H
#define DrawBlack_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class DrawBlack: public Action
{

public:
	DrawBlack(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif