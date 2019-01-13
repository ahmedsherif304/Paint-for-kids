#ifndef ADD_DRAWINGAREA_ACTION_H
#define ADD_DRAWINGAREA_ACTION_H

#include "Action.h"

//Add DrawingArea Action class
class AddDrawingAreaAction: public Action
{
private:
	Point P1;
public:
	AddDrawingAreaAction(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;
};

#endif