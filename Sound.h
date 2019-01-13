#include "Actions\\Action.h"
#pragma once
class Sound:public Action
{
	static int x;
public:
	Sound(ApplicationManager*);
	void ReadActionParameters();
	void Execute() ;
};

