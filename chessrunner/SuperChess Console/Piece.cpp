#include "pch.h"
#include <iostream>
#include "Piece.h"
#include "Cell.h"

Piece::Piece(Cell* cell, bool player)
{
	_symbol = ' ';
	_cell = cell;
	_player = player;

}

Piece::Piece(int texture, bool player, char symbol, Cell* cell)
{
	_player = player;
	_textureIndex = texture;
	_symbol = symbol;
	_cell = cell;
}

char Piece::symbol()
{
	return _symbol;
}

vector<int> Piece::getTextureIndex()
{
	vector<int> result = vector<int>();

	result.push_back(_textureIndex);
	result.push_back(_player);

	return result;
}

void Piece::replaceCell(Cell * cell)
{
	//only if the cell has this as a reference to prevent catastrophic failure
	if (cell->getPiece() == this)
		_cell = cell;
	//else cout if issue 
}

vector<Cell*> Piece::getMoveCells(vector <vector<Cell*>> board)
{
	vector<Cell*> result = vector<Cell*>();
	return result;
}

Cell * Piece::getCell()
{
	return _cell;
}

void Piece::setPlayer(bool player)
{
	_player = player;
}

bool Piece::isPlayer()
{
	return _player;
}

Piece::~Piece()
{
}
