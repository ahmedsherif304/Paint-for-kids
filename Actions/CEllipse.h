#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "..\Figures\CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;	
	
public:
	CEllipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
};

#endif