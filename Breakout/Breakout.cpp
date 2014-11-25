#include "stdafx.h"
#include "GameWindow.h"
#include "GameWindow.h"
#include "Entity.h"
#include "Rect.h"

#define RES_WIDTH	800
#define RES_HEIGHT	600
 
#define BOTTOM_BORDER	25

#define EDGE_LEFT	0
#define EDGE_RIGHT	1
#define EDGE_TOP	2
#define EDGE_BOTTOM	3

#define BORDER_RES_WIDTH	100

#define PLAYER_HEIGHT	0.05f
#define PLAYER_WIDTH	0.25f
#define PLAYER_X	PLAYER_WIDTH/2 - PLAYER_WIDTH 
#define PLAYER_Y	-0.9f

int main(void)
{		
	// Init main OpenGL Window
	GameWindow *gameWindow = new GameWindow(RES_WIDTH, RES_HEIGHT);

	// Init all game objects

	Entity* edges [4];
	edges[EDGE_TOP] = new Entity(Vector2(0,-BORDER_RES_WIDTH), Vector2(RES_WIDTH, BORDER_RES_WIDTH));
	edges[EDGE_LEFT] = new Entity(Vector2(-BORDER_RES_WIDTH,0), Vector2(BORDER_RES_WIDTH, RES_HEIGHT));
	edges[EDGE_BOTTOM] = new Entity(Vector2(0,RES_HEIGHT-BOTTOM_BORDER), Vector2(RES_WIDTH, BORDER_RES_WIDTH));
	edges[EDGE_RIGHT] = new Entity(Vector2(RES_WIDTH,0), Vector2(BORDER_RES_WIDTH, RES_HEIGHT));

	Rect *player = new Rect(Vector2(PLAYER_X, PLAYER_Y), Vector2(PLAYER_X + PLAYER_WIDTH, PLAYER_Y + PLAYER_HEIGHT));
	//Rect *ball = new Rect(Vector2( 0.5f, 0.2f),  Vector2( 0.6f, 0.1f));

	/*
	currentBall = new Ball(397.0,VERT_RES-BOTTOM_BORDER-50);
	currentBall->setTexture(textures[TEXTURE_BALL], 0.0, 0.0, 1.0, 1.0);

	currentPaddle = new Paddle(330.0, VERT_RES-BOTTOM_BORDER-20, 150.0);
	currentPaddle->setTexture(textures[TEXTURE_PADDLE], 0.0, 0.0, 1.0, 1.0);
	*/

	// GameLoop
	while (gameWindow->getRunning())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		player->Update();
		player->Render();

		//ball->Update();
		//ball->Render();

		glEnd();
		glfwSwapBuffers(gameWindow->getWindow());
		glfwPollEvents();
	}


	// delete all gameobjects etc
	delete gameWindow;

	delete edges[EDGE_TOP];
	delete edges[EDGE_LEFT];
	delete edges[EDGE_BOTTOM];
	delete edges[EDGE_RIGHT];

	delete player;	
	//delete ball;

	return 0;
}


