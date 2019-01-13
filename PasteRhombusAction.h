#pragma once

#include "Actions\Action.h"


class PasteRhombusAction: public Action
{
private:
	Point P1; //Rhombus Center
	GfxInfo RhombusGfxInfo;
public:
	PasteRhombusAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	virtual void Execute() ;
};