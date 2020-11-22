#include "pch.h"
#include "Renderer.h"
#include <iostream>

using namespace std;
Renderer::Renderer(const char* name)
{
	_height = 800;
	_width = 800;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL could not initialise! error: " << SDL_GetError() << "\n";
	}
	TTF_Init();
	
	_window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _height, _width, 0);
	if (_window == NULL)
	{
		cout << "Window couldn't be created! SDL error: " << SDL_GetError() << "\n";
	}

	_renderer = SDL_CreateRenderer(_window, -1, 0);

	_image = IMG_Load("pieces.png");
	if (_image == NULL)
	{
		cout << "Image not loaded! SDL error: " << SDL_GetError() << "\n";
	}
	_texture = SDL_CreateTextureFromSurface(_renderer, _image);
	if (_texture == NULL)
	{
		cout << "Image not loaded! SDL error: " << SDL_GetError() << "\n";
	}
	_font = TTF_OpenFont("arial.ttf", 25);
	if (_font == NULL)
	{
		cout << "Image not loaded! SDL error: " << TTF_GetError() << "\n";
	}
}

int Renderer::width()
{
	return _width;
}

int Renderer::height()
{
	return _height;
}

void Renderer::present()
{
	SDL_RenderPresent(_renderer);
}

void Renderer::clear()
{
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
}

void Renderer::renderText(std::string text, int x, int y)
{
	//create the weird SDL stuff
	SDL_Color colour = { 255, 255, 255, 255 };
	SDL_Surface * textSurface = TTF_RenderText_Solid(_font, text.c_str(), colour);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(_renderer, textSurface);

	//get text's width and height
	int w = 0;
	int h = 0;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	SDL_Rect dstrect = { x, y, w, h };

	//render it before destroying it to prevent memory leaks
	SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textSurface);
}

//renders a chess piece based on the image index
void Renderer::renderChessPiece(SDL_Rect space, int xIndex, int yIndex) {
	SDL_Rect piece = { 85 * xIndex, 85*yIndex, 85, 85 };

	SDL_RenderCopy(_renderer, _texture, &piece, &space);
}

//renders a chess piece based on the image index
void Renderer::renderChessPiece(int x, int y, int w, int h, int xIndex, int yIndex) {
	SDL_Rect rect = { x, y, w, h };
	SDL_Rect piece = { 85 * xIndex, 85 * yIndex, 85, 85 };

	SDL_RenderCopy(_renderer, _texture, &piece, &rect);
}

void Renderer::drawRect(SDL_Color colour, int x, int y, int w, int h)
{
	SDL_SetRenderDrawColor(_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderFillRect(_renderer, &rect);
}

void Renderer::drawRect(SDL_Color colour, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderFillRect(_renderer, &rect);
}

Renderer::~Renderer()
{
	//resources
	SDL_DestroyTexture(_texture);
	SDL_FreeSurface(_image);
	TTF_CloseFont(_font);

	//window
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);

	//SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
