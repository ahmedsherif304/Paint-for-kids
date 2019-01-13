#include "Resize.h"
#include "Figures\CRectangle.h"
#include"Figures\CEllipse.h"
#include "Figures\CTriangle.h"
#include "Figures\Cline.h"
#include "Figures\CRhombus.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "string.h"
using namespace std;


Resize::Resize(ApplicationManager* pApp):Action(pApp)
{
}
void Resize::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Resize.wav"),NULL,SND_FILENAME);
	if (pManager->GetSelected() !=NULL)
	{
	c=pManager->GetSelected();
	pOut->PrintMessage("Enter the ratio");	
	double x;
	string R= pIn->GetSrting(pOut);
	x=stod(R);
	if(x==.25){
	
	
	}
	else if(x==.5){}
	else if(x==2){}
	else if (x==4){}
	else pOut->PrintMessage("Please enter a ratio among 1/4,1/2,2,4");
	
	}
	else
	pOut->PrintMessage("Select the figure first");

}
void Resize::Execute(){
	ReadActionParameters();

}

Resize::~Resize(void)
{
}
