#include "CFigure.h"

int CFigure::ID = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	SetGFX(FigureGfxInfo);
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::SetGFX(GfxInfo c) {
	FigGfxInfo=c;
}
string CFigure::getcolor(color colour){
	if (colour == RED)
		return "RED";
	else if(colour == WHITE)
		return "WHITE";
	else if(colour == BLUE)
		return "BLUE";
	else if (colour == GREEN)
		return "GREEN";
	else
		return "BLACK";
}
GfxInfo CFigure::GetGFX(){return FigGfxInfo;}
