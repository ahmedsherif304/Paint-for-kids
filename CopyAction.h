
#pragma once
#include "Actions\Action.h"

class CopyAction : public Action

{int S;
public:
	CopyAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyAction();
};

