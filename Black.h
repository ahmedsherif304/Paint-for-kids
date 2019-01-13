#ifndef BLACK_H
#define BLACK_ACTION_H
#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class Black: public Action,color
{

public:
	Black(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif