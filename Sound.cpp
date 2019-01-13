#include "Sound.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

int Sound::x=0;
Sound::Sound(ApplicationManager* pApp):Action(pApp)
{x++;
}
void Sound::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(x%2!=0)
	pOut->PrintMessage("Enable sound");
	else
	pOut->PrintMessage("Disable sound");
}
void Sound::Execute(){
ReadActionParameters();
pManager->setSound();
}
