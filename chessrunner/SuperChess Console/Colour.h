#pragma once
#include "SDL.h"

class Colour
{
private:
	Uint8 _r, _g, _b, _a;
public:
	Colour()
	{
		_r = 0;
		_g = 0;
		_b = 0;
		_a = 0;
	}

	Colour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	Colour(int r, int g, int b, int a)
	{
		//making sure we don't go out of bounds
		if (r < 256)
			_r = (Uint8)r;
		else _r = 255;

		if (g < 256)
			_g = (Uint8)g;
		else _g = 255;

		if (b < 256)
			_b = (Uint8)b;
		else _b = 255;

		if (a < 256)
			_a = (Uint8)a;
		else _a = 255;
	}

	SDL_Color SDL() {
		return { _r, _g, _b, _a };
	}
};

