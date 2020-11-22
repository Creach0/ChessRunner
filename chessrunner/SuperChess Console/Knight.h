#pragma once
#include "Piece.h"
#include "Cell.h"

class Knight :
	public Piece
{
private:
	char _symbol;
public:
	Knight(Cell*, bool);
	vector<Cell*> getMoveCells(vector < vector<Cell*>>);
	~Knight();
};

