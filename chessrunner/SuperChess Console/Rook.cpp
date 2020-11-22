#include "pch.h"
#include "Rook.h"

Rook::Rook(Cell* cell, bool player) : Piece(4, player, 'R', cell)
{
}

//rooks get cells horizontal and vertical to them
vector<Cell*> Rook::getMoveCells(vector < vector<Cell*>> board)
{
	vector<Cell *> result = vector<Cell*>();
	Cell * containerCell = getCell();

	int x = containerCell->getX();
	int y = containerCell->getY();

	//all cells right to this
	for (int i = x + 1; i < BOARD_WIDTH; i++)
	{
		result.push_back(new Cell(i, y, containerCell->getYOffset(), this));

		if (board[i][y]->getPiece() != nullptr)
			break;
	}

	//all cells left to this
	for (int i = x - 1; i > -1; i--)
	{
		result.push_back(new Cell(i, y, containerCell->getYOffset(), this));

		if (board[i][y]->getPiece() != nullptr)
			break;
	}

	//all cells below this
	for (int i = y + 1; i < BOARD_HEIGHT; i++)
	{
		result.push_back(new Cell(x, i, containerCell->getYOffset(), this));

		if (board[x][i]->getPiece() != nullptr)
			break;
	}

	//all cells above this
	for (int i = y - 1; i > 0; i--)
	{
		result.push_back(new Cell(x, i, containerCell->getYOffset(), this));

		if (board[x][i]->getPiece() != nullptr)
			break;
	}

	return result;
}

Rook::~Rook()
{
}
