#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions\Action.h"
#include "Actions\SelectAction.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	 
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	color* FigColor[MaxFigCount];
	color colour,colour2,OldColor;
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	//Pointers to Input and Output classes
	bool sound;
	Input *pIn;
	Output *pOut;
public:	
	int Switch;
	ApplicationManager(); 
	~ApplicationManager();
	bool isFilled();
	bool Exitation;

	CFigure* GetFigure(int,int) const;
	void ChangeColorAction(color);
	void ChangeDrawColorAction(color X);
	void saveall(ofstream &Outfile);
	string getcolor(color colour);
	void savebytype(ofstream &Outfile2, string type);
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void UnSelect(Point);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFigure();
	CFigure *GetFigure(Point) const; //Search for a figure given a point inside the figure
	int GetFigCount();
	CFigure* GetSelected (); //get a pointer to the selected figure
	void Set_Clipboard(CFigure*); // take a pointer to the figure from the CopyAction or CutAction classes
	CFigure* Get_Clipoard();
	CFigure* PickRandomFigure();
	color*& PickRandomColor();
	void setFigNums(int&,int&,int&,int&,int&);
	void setColorNums(int&,int&,int&,int&,int&,int&);

	void Set_Old_Color(color);
	color Get_Old_Color();
	color GetColor();
	color GetColor2();
	void setSound();
	bool getSound();
	void BFront();
	void BBack();

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif