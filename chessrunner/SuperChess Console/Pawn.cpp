#include "pch.h"
#include "Pawn.h"

Pawn::Pawn(Cell* cell, bool player) : Piece(5, player, 'p', cell)
{
}

vector<Cell*> Pawn::getMoveCells(vector < vector<Cell*>> board)
{
	vector<Cell *> result = vector<Cell*>();
	Cell* containerCell = getCell();

	int x = containerCell->getX();
	int y = containerCell->getY();

	if (y-1>-1) {//only 2, we're moving up the board
		if (x-1 > -1)//up and left
			result.push_back(new Cell(x-1, y-1, containerCell->getYOffset(), this));
		if (x+1 < BOARD_WIDTH) //up and right
			result.push_back(new Cell(x+1, y-1, containerCell->getYOffset(), this));
	}

	return result;
}


Pawn::~Pawn()
{
}
