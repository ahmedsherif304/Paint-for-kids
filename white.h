#ifndef WHITE_H
#define WHITE_ACTION_H
#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class white: public Action,color
{

public:
	white(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif