#include"Actions\Action.h"
#include "ApplicationManager.h"
#include"GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\SaveAction.h"
#pragma once
class switchToPlayAction: public Action
{
	SaveAction* s;
public:
	switchToPlayAction(ApplicationManager * );
	void ReadActionParameters() ;
	void Execute() ;
	~switchToPlayAction(void);
};

