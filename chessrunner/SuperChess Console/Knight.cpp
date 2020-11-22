#include "pch.h"
#include "Knight.h"
#include "myConsts.h"

Knight::Knight(Cell* cell, bool player) : Piece(3, player, 'N', cell)
{
}

vector<Cell*> Knight::getMoveCells(vector < vector<Cell*>> board)
{
	vector<Cell *> result = vector<Cell*>();
	Cell* containerCell = getCell();

	int x = containerCell->getX();
	int y = containerCell->getY();

	int xDiff[8] = {-2,-2,-1,1,2,2,1,-1};
	int yDiff[8] = {-1,1,-2,-2,1,-1,2,2};

	for (int i = 0; i < 8; i++)
	{
		int newX = x + xDiff[i];
		int newY = y + yDiff[i];

		//if within bounds
		if (newX > -1 && newX < BOARD_WIDTH && newY > -1 && newY < BOARD_HEIGHT)
			result.push_back(new Cell(newX, newY, containerCell->getYOffset(), this));
	}

	return result;
}

Knight::~Knight()
{
}
