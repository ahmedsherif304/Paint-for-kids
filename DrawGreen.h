#ifndef DrawGreen_H
#define DrawGreen_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class DrawGreen: public Action
{

public:
	DrawGreen(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif