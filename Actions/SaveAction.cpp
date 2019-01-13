#include "SaveAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager * pApp):Action(pApp)
{}
SaveAction::SaveAction(ApplicationManager * pApp,string x):Action(pApp){
	file_name=x;
}
 void SaveAction::ReadActionParameters(){
    Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(file_name!="SavePlay"){
	pOut->PrintMessage(" please enter file name ");
	file_name=pIn->GetSrting(pOut);
	}
	pOut->PrintMessage("your file name will be :"+ file_name);
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void SaveAction::Execute() 
{	ReadActionParameters();
    Output* pOut= pManager->GetOutput();
	ofstream outfile;
	outfile.open(file_name+".txt");
	pManager->saveall(outfile);
	outfile.close();

}