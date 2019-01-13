#pragma once

#include "Actions\Action.h"
class PasteLineAction:public Action

{
	private:
	Point temp;
	Point P1;
	Point P2;

	GfxInfo LineGfxInfo;

public:
	PasteLineAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~PasteLineAction();
};

