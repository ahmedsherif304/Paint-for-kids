#ifndef RED_H
#define RED_ACTION_H
#include "Actions/Action.h"
#include "Figures/CFigure.h"
//Add Rectangle Action class
class Red: public Action,color
{

public:
	Red(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;

};

#endif
