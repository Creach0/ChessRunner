#include "pch.h"
#include <iostream>
#include <SDL.h>
#include "Board.h"
#include "Renderer.h"

#undef main

int main()
{
	Board gameBoard = Board();
	
	Renderer* renderer = new Renderer("SuperChess");

	bool exitNotRequested = true;

	SDL_Event e;
	while (exitNotRequested)
	{
		//clear
		renderer->clear();

		//handle input
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type)
			{
			case SDL_QUIT:
				exitNotRequested = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				gameBoard.handleClick();
				break;
			}
		}
		//update
		gameBoard.update();

		//render
		gameBoard.render(renderer);
		renderer->present();

		//wait
		SDL_Delay(16);

	}

	delete renderer;
	return 0;
}