#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 70;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar() const
{
	//Clear Tool bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";
	MenuItemImages[ITM_Circ]="images\\MenuItems\\elipse.jpg";
	MenuItemImages[ITM_Rhombus]="images\\MenuItems\\rhombus.jpg";
	MenuItemImages[ITM_Tri]="images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_Line]="images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_Select]="images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_Color]="images\\MenuItems\\change_color.jpg";
	MenuItemImages[ITM_Del]="images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_Copy]="images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_Cut]="images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_Paste]="images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_Save]="images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_Load]="images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_Play]="images\\MenuItems\\play_mode.jpeg";
	MenuItemImages[ITM_SAVE_TYPE]="images\\MenuItems\\save_type.jpg";
	MenuItemImages[ITM_BRING_BACK]="images\\MenuItems\\backward.jpg";
	MenuItemImages[ITM_BRING_FRONT]="images\\MenuItems\\front.jpg";
	MenuItemImages[ITM_RESIZE]="images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_SOUND]="images\\MenuItems\\SOUND.jpg";
	MenuItemImages[ITM_DrawColor]="images\\MenuItems\\change_draw.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(GOLD, 3);
	pWind->DrawLine(0, UI.ToolBarHeight+5, UI.width, UI.ToolBarHeight+5);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar() const{
	UI.InterfaceMode = MODE_COLOR;
	string MenuItemImages[COLOR_ITEM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE]="images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_GREEN]="images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE]="images\\MenuItems\\blue.jpg";

	for(int i=0; i<COLOR_ITEM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(GOLD,3);
	pWind->DrawLine(0, UI.ToolBarHeight+5, UI.width, UI.ToolBarHeight+5);	
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawColorToolBar() const{
	UI.InterfaceMode = MODE_DRAWCOLOR;
	string MenuItemImages[DrawCOLOR_ITEM_COUNT];
	MenuItemImages[ITM_RED2] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_BLACK2] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE2]="images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_GREEN2]="images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE2]="images\\MenuItems\\blue.jpg";

	for(int i=0; i<DrawCOLOR_ITEM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(GOLD, 3);
	pWind->DrawLine(0, UI.ToolBarHeight+5, UI.width, UI.ToolBarHeight+5);	
}
void Output::CreatePlayToolBar() const
{
	
	
	UI.InterfaceMode = MODE_PLAY;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_DRAWMODE] = "images\\MenuItems\\draw_mode.jpg";
	MenuItemImages[ITM_CLOSE] = "images\\MenuItems\\exit.jpg";
	MenuItemImages[ITM_PICK] = "images\\MenuItems\\pick.jpg";
	MenuItemImages[ITM_PICK_COLOR]="images\\MenuItems\\pick_color.jpg";

	
	
	

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(GOLD, 3);
	pWind->DrawLine(0, UI.ToolBarHeight+5, UI.width, UI.ToolBarHeight+5);		
	
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);		
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output ::DRAW_LINE(Point P1,Point P2,GfxInfo LineGfxInfo,bool selected)const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LineGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	
	
		style = FILLED;		
		pWind->SetBrush(LineGfxInfo.FillClr);
	

	pWind->DrawLine(P1.x,P1.y,P2.x,P2.y);}
void Output::DrawEllipse(Point P1,GfxInfo EllipseGfxInfo,bool selected=false)const
{
	Point P2,P3;
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = EllipseGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,UI.PenWidth );
	drawstyle style;
	if (EllipseGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(EllipseGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	P2.x=P1.x+40;
	P2.y=P1.y+90;
	P3.x=P1.x-40;
	P3.y=P1.y-90;
	pWind->DrawEllipse(P2.x,P2.y,P3.x,P3.y,style);
}

void Output::DrawTri(Point P1,Point P2,Point P3,GfxInfo TriGfxInfo,bool selected)const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,UI.PenWidth );
	drawstyle style;
	if (TriGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	pWind->DrawTriangle(P1.x,P1.y,P2.x,P2.y,P3.x,P3.y,style);}


void Output:: DrawRhombus(Point P1,GfxInfo RhombusGfxInfo ,bool selected)const
{
	Point P2,P3,P4,P5;
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RhombusGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,UI.PenWidth );
	drawstyle style;
	if (RhombusGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RhombusGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	P2.x=P1.x+50;
	P2.y=P1.y;
	P3.x=P1.x;
	P3.y=P1.y+100;
	P4.x=P1.x-50;
	P4.y=P1.y;
	P5.x=P1.x;
	P5.y=P1.y-100;
	int arrx[4]={P2.x,P3.x,P4.x,P5.x};
	int arry[4]={P2.y,P3.y,P4.y,P5.y};
	pWind->DrawPolygon(arrx,arry,4,style);
}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

