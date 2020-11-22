#include "pch.h"
#include "Cell.h"
#include "Renderer.h"


Cell::Cell(int x, int y, int * yOffset)
{
	_xCoord = x;
	_yCoord = y;
	_width = 100;
	_height = 100;
	_content = nullptr;
	_yOffset = yOffset;
	updateColour(false);
}

Cell::Cell(int x, int y, int * yOffset, Piece * piece)
{
	_content = piece;
	_xCoord = x;
	_yCoord = y;
	_width = 100;
	_height = 100;
	_yOffset = yOffset;
	updateColour(false);
}

int Cell::getX()
{
	return _xCoord;
}

int Cell::getY()
{
	return _yCoord;
}

int* Cell::getYOffset()
{
	return _yOffset;
}

int Cell::getXpix()
{
	return _xCoord * _width;
}

int Cell::getYpix()
{
	return (_yCoord * _height)+(*_yOffset);
}

//used to push everything down when we generate a new row
void Cell::incrementYCoord()
{
	_yCoord++;
}

void Cell::updateColour(bool swap)
{
	//is x even != is y even
	if (((_xCoord % 2 == 0) != (_yCoord % 2 == 0)) == swap)
		_colour = Colour(68, 13, 15, 255);
	else
		_colour = Colour(25, 23, 22, 255);
}

void Cell::changePiece(Piece* piece)
{
	_content = piece;
}

Piece * Cell::getPiece()
{
	return _content;
}

void Cell::render(Renderer * renderer)
{
	int x = getXpix();
	int y = getYpix();
	
	//draw square
	renderer->drawRect(_colour.SDL(), x, y, _width, _height);
	
	//draw piece
	if (_content != nullptr) {
		vector<int> textureIndex = _content->getTextureIndex();
		renderer->renderChessPiece(x+7, y+7, 85, 85, textureIndex[0], textureIndex[1]);
	}
}

void Cell::update(bool swap)
{
	updateColour(swap);
}

bool Cell::containsPlayer()
{
	if (_content == nullptr)
		return false;
	else
		return _content->isPlayer();
}

void Cell::changeColour(int r, int g, int b, int a)
{
	_colour = Colour(r, g, b, a);
}

Cell::~Cell()
{
	delete(_content);
}
