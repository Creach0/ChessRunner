#pragma once
#include <vector>
#include "Cell.h"
#include "Piece.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


class Renderer;
using std::vector;
class Board
{
private:
	vector<vector<Cell*>> _cells;
	int* _yOffset;
	bool _invert, _gameOver;
	int _score;
	Piece * _playerPiece;
public:
	Board();
	void generateRandomPiece(Cell * cell);
	void replaceCell(Cell*);
	vector<vector<Cell*>> cells();
	void displayMoves(int, int);
	void update();
	bool isGameOver();
	vector<Cell*> generateRow();
	//push_front row
	void pushRow(vector<Cell*>);
	//pop_back row
	void popRow();
	void render(Renderer * renderer);
	//handle a click, which is essentially an attempt to move
	void handleClick();
	~Board();
};