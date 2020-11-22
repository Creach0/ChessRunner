#pragma once
#include "Piece.h"
#include "Cell.h"
#include "myConsts.h"

class Queen :
	public Piece
{
private:
	char _symbol;
public:
	Queen(Cell*, bool);
	vector<Cell*> getMoveCells(vector < vector<Cell*>>);
	~Queen();
};