#include "stdafx.h"

#include "OpenGLRenderer.h"
#include "Direct3dRenderer.h"
#include "Breakout.h"

// include the basic windows header files and the Direct3D header file
#include <windows.h>

int main(void)
{	
	//IRenderer* renderer =  new OpenGLRenderer();
	IRenderer* renderer =  new Direct3dRenderer();
	Game* game =  new Breakout(renderer);

	// calls the mainloop, will only return if the game is done;
	game->start();		

	delete renderer;
	delete game;

	return 0;
}