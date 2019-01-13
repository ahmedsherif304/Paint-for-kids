#include "Action.h"
#include <string>
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <fstream>

class SaveByTypeAction : public Action
{
private:
	ofstream Outfile2;
	string file_name;
	string type;
public:
	SaveByTypeAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	
};

