#ifndef CELLIPSE_H
#define CELLIPSE_H
#include<iostream>
using namespace std;
#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	int ID2;
	int IDPaste;
	Point Corner1;	
	
public:
	CEllipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsHere(Point p);
	int getID();
	virtual void Load(ifstream &Infile);
	virtual void Save(ofstream &OutFile);
	void PrintInfo(Output* pOut);
	virtual string gettype();
};

#endif