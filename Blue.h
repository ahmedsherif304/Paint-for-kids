#ifndef BLUE_H
#define BLUE_ACTION_H
#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class Blue: public Action,color
{

public:
	Blue(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif