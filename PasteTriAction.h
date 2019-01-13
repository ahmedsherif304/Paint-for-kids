#pragma once
#include "Actions\Action.h"

class PasteTriAction:public Action

{
	protected:
	Point temp;
	Point P1;
	Point P2;
	Point P3;

	GfxInfo TriGfxInfo;

public:
	PasteTriAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~PasteTriAction();
};


