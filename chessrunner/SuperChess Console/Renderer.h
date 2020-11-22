#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class Renderer
{
private:
	int _height, _width;

	SDL_Renderer * _renderer;
	SDL_Window* _window;
	SDL_Texture * _texture;
	SDL_Surface * _image;
	TTF_Font * _font;
public:
	Renderer(const char* name);
	int width();
	int height();
	//present to window
	void present();
	//clear window
	void clear();
	void renderText(std::string text, int,int);
	void renderChessPiece(SDL_Rect space, int xIndex, int yIndex);
	void renderChessPiece(int x, int y, int w, int h, int xIndex, int yIndex);
	void drawRect(SDL_Color, int,int,int,int);
	void drawRect(SDL_Color colour, SDL_Rect rect);
	~Renderer();
};

