#pragma once
#include "Actions\Action.h"

class PasteRectAction:public Action

{
	protected:
	Point temp;
	Point P1;
	Point P2;

	GfxInfo RectGfxInfo;

public:
	PasteRectAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~PasteRectAction();
};

