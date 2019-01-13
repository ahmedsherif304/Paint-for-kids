#ifndef ADD_RHOMBUS_ACTION_H
#define ADD_RHOMBUS_ACTION_H

#include "Action.h"

//Add Rhombus Action class
class AddRhombusAction: public Action
{
private:
	Point P1; //Rhombus Center
	GfxInfo RhombusGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
};

#endif