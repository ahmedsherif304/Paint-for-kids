#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H
#include "Action.h"
class SelectAction:public Action 
{private:
Point P1;
public:
	SelectAction(ApplicationManager *pApp);
	void SetPoint(Point);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	Point getPoint();
};

#endif