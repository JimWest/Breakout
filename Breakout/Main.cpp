#include "stdafx.h"

#include "OpenGLRenderer.h"
#include "Breakout.h"

int main(void)
{	
	IRenderer* renderer =  new OpenGLRenderer();
	Game* game =  new Breakout(renderer);

	// calls the mainloop, will only return if the game is done;
	game->start();		

	delete renderer;
	delete game;

	return 0;
}