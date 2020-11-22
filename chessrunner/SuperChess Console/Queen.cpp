#include "pch.h"
#include "Queen.h"

Queen::Queen(Cell* cell, bool player) : Piece(1, player, 'Q', cell)
{
}

vector<Cell*> Queen::getMoveCells(vector < vector<Cell*>> board)
{
	vector<Cell *> result = vector<Cell*>();
	Cell* containerCell = getCell();

	int x = containerCell->getX();
	int y = containerCell->getY();

	//all cells right to this
	for (int i = x+1; i < BOARD_WIDTH; i++)
	{
		result.push_back(new Cell(i, y, containerCell->getYOffset(), this));

		if (board[i][y]->getPiece() != nullptr)
			break;
	}

	//all cells left to this
	for (int i = x-1; i > -1; i--)
	{
		result.push_back(new Cell(i, y, containerCell->getYOffset(), this));

		if (board[i][y]->getPiece() != nullptr)
			break;
	}

	//all cells below this
	for (int i = y+1; i < BOARD_HEIGHT; i++)
	{
		result.push_back(new Cell(x, i, containerCell->getYOffset(), this));

		if (board[x][i]->getPiece() != nullptr)
			break;
	}

	//all cells above this
	for (int i = y-1; i > 0; i--)
	{
		result.push_back(new Cell(x, i, containerCell->getYOffset(), this));

		if (board[x][i]->getPiece() != nullptr)
			break;
	}


	x = containerCell->getX();
	y = containerCell->getY();

	//all cells right/up (+/-)
	x++;
	y--;
	while (x < BOARD_WIDTH && y > -1)
	{
		result.push_back(new Cell(x, y, containerCell->getYOffset(), this));
		if (board[x][y]->getPiece() != nullptr)
			break;
		x++;
		y--;
	}

	x = containerCell->getX();
	y = containerCell->getY();
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

	x = containerCell->getX();
	y = containerCell->getY();
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

	x = containerCell->getX();
	y = containerCell->getY();
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

Queen::~Queen()
{
}
