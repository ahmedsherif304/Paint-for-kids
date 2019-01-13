#ifndef Green_H
#define GREEN_ACTION_H
#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class Green: public Action,color
{

public:
	Green(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;

};

#endif