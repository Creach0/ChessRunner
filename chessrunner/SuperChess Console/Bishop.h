#pragma once
#include "Piece.h"
#include "Cell.h"
#include "myConsts.h"

class Bishop :
	public Piece
{
private:
	char _symbol;
public:
	Bishop(Cell*, bool);
	vector<Cell*> getMoveCells(vector < vector<Cell*>> board);
	~Bishop();
};

