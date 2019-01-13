#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,
MODE_COLOR,	//Playing mode
MODE_DRAWCOLOR
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_RECT,		//Recangle item in menu

	//TODO: Add more items names here
	ITM_Circ,
	ITM_Rhombus,
	ITM_Tri,
	ITM_Line,
	ITM_Select,
	ITM_Color,
	ITM_DrawColor,
	ITM_Copy,
	ITM_Cut,
	ITM_Paste,
	ITM_Save,
	ITM_SAVE_TYPE,
	ITM_Load,
	ITM_Del,
	ITM_Play,
	ITM_SOUND,
	ITM_RESIZE,
	ITM_BRING_FRONT,
	ITM_BRING_BACK,//Recangle item in menu
	
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum DrawColorMenuItem

{
	ITM_RED2,
	ITM_BLUE2,
	ITM_WHITE2,
	ITM_BLACK2,
	ITM_GREEN2,
	
	DrawCOLOR_ITEM_COUNT
};
enum PlayMenuItem //The items of the Play menu (you should add more items)
{ITM_PICK,
ITM_PICK_COLOR,
ITM_DRAWMODE,
ITM_CLOSE,
PLAY_ITM_COUNT

	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here

			//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorMenuItem

{
	ITM_RED,
	ITM_BLUE,
	ITM_WHITE,
	ITM_BLACK,
	ITM_GREEN,
	
	COLOR_ITEM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif