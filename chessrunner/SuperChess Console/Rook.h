#pragma once
#include "Piece.h"
#include "Cell.h"
#include "myConsts.h"

class Rook :
	public Piece
{
private:
	char _symbol;
public:
	Rook(Cell*, bool);
	vector<Cell*> getMoveCells(vector < vector<Cell*>>);
	~Rook();
};

 