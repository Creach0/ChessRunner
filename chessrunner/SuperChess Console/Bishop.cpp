#include "pch.h"
#include "Bishop.h"

Bishop::Bishop(Cell* cell, bool player) : Piece(2, player,'B', cell)
{
}

vector<Cell*> Bishop::getMoveCells(vector < vector<Cell*>> board)
{
	vector<Cell *> result = vector<Cell*>();

	Cell* containerCell = getCell();

	int x = containerCell->getX();
	int y = containerCell->getY();

	//all cells right/up (+/-)
	x++;
	y--;
	while(x < BOARD_WIDTH && y > -1)
	{
		result.push_back(new Cell(x, y, containerCell->getYOffset(), this));
		if (board[x][y]->getPiece() != nullptr)
			break;
		x++;
		y--;
	}

	x = getCell()->getX();
	y = getCell()->getY();
	//all cells right/down (+/+)
	x++;
	y++;
	while (x < BOARD_WIDTH && y < BOARD_HEIGHT)
	{
		result.push_back(new Cell(x, y, containerCell->getYOffset(), this));
		if (board[x][y]->getPiece() != nullptr)
			break;
		x++;
		y++;
	}

	x = getCell()->getX();
	y = getCell()->getY();
	//all cells left/up (-/-)
	x--;
	y--;
	while (x > -1 && y > -1)
	{
		result.push_back(new Cell(x, y, containerCell->getYOffset(), this));
		if (board[x][y]->getPiece() != nullptr)
			break;
		x--;
		y--;
	}

	x = getCell()->getX();
	y = getCell()->getY();
	//all cells left/down (-/+)
	x--;
	y++;
	while (x > -1 && y < BOARD_HEIGHT)
	{
		result.push_back(new Cell(x, y, containerCell->getYOffset(), this));
		if (board[x][y]->getPiece() != nullptr)
			break;
		x--;
		y++;
	}

	return result;
}

Bishop::~Bishop()
{
}
