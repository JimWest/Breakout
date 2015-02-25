#include "stdafx.h"

#include "OpenGLRenderer.h"
#include "Direct3dRenderer.h"
#include "Breakout.h"

using namespace std;

int main(void)
{	
	cout << "Choose the render engine:\n";
	cout << "1: OpenGL\n";
	cout << "2: Direct3D\n";

	int engine;
	cin >> engine;

	IRenderer* renderer;

	if (engine == 1)
	{
		renderer =  new OpenGLRenderer();
	}
	else
	{
		renderer =  new Direct3dRenderer();
	}

	Game* game =  new Breakout(renderer);

	// calls the mainloop, will only return if the game is done;
	game->start();		

	delete renderer;
	delete game;

	return 0;
}