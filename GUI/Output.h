#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void ClearToolBar() const;
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorToolBar() const; //create color tool bar
	void CreatePickToolBar() const; //create pick tool bar
	void CreateDrawColorToolBar() const;
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	color getclr(int,int);
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DRAW_LINE(Point P1,Point P2,GfxInfo,bool selected=false)const;
	void DrawEllipse(Point P1,GfxInfo EllipseGfxInfo,bool style)const;
	void DrawTri(Point P1,Point P2,Point P3,GfxInfo TriGfxInfo,bool selected)const;
	void DrawRhombus(Point P1,GfxInfo RhombusGfxInfo ,bool selected)const;
	///Make similar functions for drawing all other figure types.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif