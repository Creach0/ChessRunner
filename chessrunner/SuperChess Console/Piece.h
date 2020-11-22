#pragma once
#include <string>
#include <vector>

class Cell;

using std::vector;
using std::string;
class Piece
{
private:
	char _symbol;
	bool _player;
	int _textureIndex;
	Cell* _cell;
public:
	Piece(Cell*, bool);
	Piece(int, bool, char, Cell*);
	char symbol();
	//texture index is for renderer to find the texture on the base image
	vector<int> getTextureIndex();
	void replaceCell(Cell *);
	//take the initial cell (_cell), and create all possible cells that a piece could move to. The returned cell contains the piece (this)
	virtual vector<Cell*> getMoveCells(vector<vector<Cell*>>);
	Cell * getCell();
	void setPlayer(bool);
	bool isPlayer();


	~Piece();
};

