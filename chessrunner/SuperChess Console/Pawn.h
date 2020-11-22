#pragma once
#include "Piece.h"
#include "Cell.h"
#include "myConsts.h"

class Pawn :
	public Piece
{
private:
	char _symbol;
public:
	Pawn(Cell*, bool);
	vector<Cell*> getMoveCells(vector < vector<Cell*>>);
	~Pawn();
};

