#pragma once

#include "Actions\Action.h"

//Add Ellipse Action class
class PasteEllipseAction: public Action
{
private:
	Point P1; //Ellipse center point
	GfxInfo EllipseGfxInfo;
public:
	PasteEllipseAction(ApplicationManager *pApp);
	
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
};

