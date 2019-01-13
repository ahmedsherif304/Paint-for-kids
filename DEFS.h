#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	SAVE,           //Save the whole graph to a file
	SAVE_TYPE,
	RESIZE,
	SOUND,
	BRING_FRONT,
	BRING_BACK,
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	SELECT,
	COPY,
	CUT,
	PASTE,
	PASTE_RECT,
	PASTE_TRI,
	PASTE_LINE,
	PASTE_ELLIPSE,
	PASTE_RHOMBUS,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,        //Switch interface to Play mode
	PICK,
	PICK_COLOR,
	C_BLACK,
	C_RED,
	C_WHITE,
	C_GREEN,
	C_BLUE,
	C_BLACK2,
	C_RED2,
	C_WHITE2,
	C_GREEN2,
	C_BLUE2
	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif