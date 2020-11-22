#include "pch.h"
#include "Board.h"
#include <ctime>
#include "myConsts.h"
#include "Renderer.h"

Board::Board()
{
	srand(time(NULL));
	_invert = false;
	_score = 0;
	_gameOver = false;
	_yOffset = new int;
	*_yOffset = -100;

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		_cells.push_back(vector<Cell*>());
		for (int j = 0; j < BOARD_HEIGHT +1; j++)
		{
			Cell* cell = new Cell(i, j, _yOffset);
			_cells[i].push_back(cell);

			//we start as a queen on d1, so don't put a random piece there
			if (i != 3 || j != 7)
			{
				generateRandomPiece(cell);
			}
			else
			{
				_playerPiece = new Queen(cell, true);
				cell->changePiece(_playerPiece);
			}
		}
	}
}

void Board::generateRandomPiece(Cell * cell)
{
	int piecenum = (rand() % 100) + 1;

	if (piecenum <= 2) {//2% odds
		cell->changePiece(new Queen(cell, false));
	}
	else if (piecenum <= 10) {//8% odds
		cell->changePiece(new Bishop(cell, false));
	}
	else if (piecenum <= 25) {//15% odds
		cell->changePiece(new Pawn(cell, false));
	}
	else if (piecenum <= 35) {//10%
		cell->changePiece(new Knight(cell, false));
	}
	else if (piecenum <= 40) {//5%
		cell->changePiece(new Rook(cell, false));
	}
}

void Board::replaceCell(Cell * newCell)
{
	int x = newCell->getX();
	int y = newCell->getY();

	delete(_cells[x][y]);
	_cells[x][y] = newCell;
}

vector<vector<Cell*>> Board::cells()
{
	return _cells;
}

void Board::displayMoves(int x, int y)
{
	vector<Cell*> moves = _cells[x][y]->getPiece()->getMoveCells(_cells);

	for (auto move : moves)
	{
		move->changeColour(0,0,255,0);
		replaceCell(move);
	}
}

void Board::update()
{
	bool hitEnd = false;
	(*_yOffset)++;
	if (*_yOffset > -1)
	{
		pushRow(generateRow());
		popRow();
		*(_yOffset) = -100;
		hitEnd = true;
		if (!_gameOver)
			_score++;
		_invert = !_invert;
	}

	_gameOver = true;
	for (auto row : _cells)
	{
		for (auto cell : row)
		{
			if (hitEnd) {
				cell->incrementYCoord();
				cell->updateColour(_invert);
			}
			if (cell->containsPlayer())
			{
				_gameOver = false;
			}
		}
	}
}

bool Board::isGameOver()
{
	return _gameOver;
}

vector<Cell*> Board::generateRow()
{
	vector<Cell*> result = vector<Cell*>();
	for (int i = 0; i < BOARD_WIDTH; i++) {
		Cell * cell = new Cell(i, -1, _yOffset);//we're assuming that a row is going to be the top row, hence y=0
		result.push_back(cell);

		generateRandomPiece(cell);
	}

	return result;
}

void Board::pushRow(vector<Cell*> row)
{
	for (int i = 0; i < _cells.size(); i++)
	{
		_cells[i].insert(_cells[i].begin(), row[i]);
	}
}

void Board::popRow()
{
	for (int i = 0; i < _cells.size(); i++)
	{
		delete _cells[i].back();
		_cells[i].pop_back();
	}
}

void Board::render(Renderer * renderer)
{
	for (auto row : _cells)
	{
		for (auto cell : row)
		{
			cell->render(renderer);
		}
	}

	if (isGameOver())
		renderer->renderText("Game Over :(", 330, 390);
	renderer->renderText("Score: " + std::to_string(_score), 20,20);
}

void Board::handleClick()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	y = y - *_yOffset;

	//we can get the cell being hovered with an index lookup of the floor of mousepos/100
	Cell * clickedCell = _cells[floor(x / 100)][floor(y / 100)];
	Piece * piece = clickedCell->getPiece();
	
	if (piece != nullptr) // do nothing if there's no piece to take
	{
		//get available moves
		vector<Cell *> moves = _playerPiece->getMoveCells(_cells);
		
		//compare moves to the piece
		for (int i = 0; i < moves.size(); i++)
		{
			//this looks hellish but it's just 'are x and y the same'
			if (moves[i]->getX() == clickedCell->getX() && moves[i]->getY() == clickedCell->getY()) {
				//remove piece from cell
				_playerPiece->getCell()->changePiece(nullptr);
				//make player piece
				_playerPiece = piece;
				piece->setPlayer(true);
				break;
			}
		}
	}
}


Board::~Board()
{
	for (auto row : _cells)
	{
		for (auto cell : row)
		{
			delete(cell);
		}
	}
}
