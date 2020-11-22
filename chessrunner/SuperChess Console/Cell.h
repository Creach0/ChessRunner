#pragma once
#include <iostream>
#include "Cell.h"
#include "Piece.h"
#include "Colour.h"

class Piece;
class Renderer;
class Cell
{
private:
	Piece* _content;
	int _width, _height, _xCoord, _yCoord;
	int * _yOffset;
	Colour _colour;
public:
	Cell(int, int, int *);
	Cell(int, int, int *, Piece*);
	int getX();
	int getY();
	//yOffset used for partial board movements
	int* getYOffset();
	//pixel coordinates, as opposed to board coords.
	int getXpix();
	int getYpix();
	//useful for when we want to shove everything on the board down one space, when we create a new row at the top.
	void incrementYCoord();
	//updates colour based on coordinates, inverts if swap is true
	void updateColour(bool swap);
	void changePiece(Piece * piece);
	Piece* getPiece();
	void render(Renderer * renderer);
	void update(bool swap);
	//if the piece in this cell is the player piece
	bool containsPlayer();
	//force update colour
	void changeColour(int r, int g, int b, int a);

	~Cell();
};