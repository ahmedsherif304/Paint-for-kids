#ifndef DrawWhite_H
#define DrawWhite_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class DrawWhite: public Action
{

public:
	DrawWhite(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif