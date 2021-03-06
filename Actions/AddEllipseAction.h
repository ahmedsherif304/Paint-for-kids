#ifndef ADD_ELLIPSE_ACTION_H
#define ADD_ELLIPSE_ACTION_H

#include "Action.h"

//Add Ellipse Action class
class AddEllipseAction: public Action
{
private:
	Point P1; //Ellipse center point
	GfxInfo EllipseGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);
	
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
};

#endif