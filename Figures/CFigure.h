#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	static	int  ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.
 
public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetGFX(GfxInfo);
	GfxInfo GetGFX();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool IsHere(Point p)=0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual int getID()=0;		//Getting the ID of the type of the figure to paste it
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	virtual string gettype()=0;	//changes the figure's filling color
	string getcolor(color colour);
	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;//	//print all figure info on the status bar
};

#endif