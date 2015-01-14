#include "stdafx.h"
#include "StaticBox.h"
#include "DynamicBox.h"
#include "StaticBox.h"
#include "Ball.h"

#include <iostream>
#include <string>

#include "IRenderer.h"
#include "OpenGLRenderer.h"

#define RES_WIDTH	800
#define RES_HEIGHT	600

#define COUNTDOWN_START	3

#define BORDER_LEFT	0
#define BORDER_RIGHT	1
#define BORDER_TOP	2
#define BORDER_BOTTOM	3

#define BORDER_RES_WIDTH	100

#define PLAYER_HEIGHT	0.05f
#define PLAYER_WIDTH	0.25f
#define PLAYER_X	PLAYER_WIDTH/2 - PLAYER_WIDTH 
#define PLAYER_Y	-0.9f

#define BALL_HEIGHT	0.05f
#define BALL_WIDTH	0.05f
#define BALL_X	BALL_WIDTH / 2 - BALL_WIDTH
#define BALL_Y	PLAYER_Y + 0.1f
#define BALL_velocity_X	1
#define BALL_velocity_Y	1

IRenderer* renderer;
DynamicBox* player;
Ball* ball;
StaticBox* borders [4];
StaticBox* collisionObjects[99];
StaticBox* renderObject[99];
double countDownEnd;


void resetGame()
{	
	player->setOrigin(Vector2(PLAYER_X, PLAYER_Y));
	ball->setOrigin(Vector2( BALL_X, BALL_Y));
	ball->setVelocity(Vector2(BALL_velocity_X, BALL_velocity_Y));

	double currentFrame = renderer->getTime();
	countDownEnd = renderer->getTime() + COUNTDOWN_START;

}


void checkCollisions()
{

	Collision playerCol = ball->getCollision(player);
	if (playerCol.colided)
	{
		ball->bounceOff(playerCol);
	}
	
	if (ball->getOrigin().x + ball->getWidth() >= borders[BORDER_RIGHT]->getOrigin().x)
	{
		int a = 1;
	}


	// wall collision
	
	for (int i = 0; i<=3; i++)
	{
		if (i == BORDER_BOTTOM)
		{
			int a = 1;
		}

		Collision col = ball->getCollision(borders[i]);
		if (col.colided)
		{
			if (i == BORDER_BOTTOM)
			{
				resetGame();
				return;
			}
			else
			{
				ball->bounceOff(col);
				break;
			}
			
		}

	}
	

}



int main(void)
{		
	renderer = new OpenGLRenderer();
	renderer->createWindow(RES_WIDTH, RES_HEIGHT);

	// Init all game objects
	borders[BORDER_TOP] = new StaticBox(Vector2(-1.4f, 0.8f), 2.8f, 0.01f);
	borders[BORDER_LEFT] = new StaticBox(Vector2(-1.35f, -0.95f), 0.01f, 2.8f);
	borders[BORDER_BOTTOM] = new StaticBox(Vector2(-1.35f, -0.95f),2.8f, 0.01f);
	borders[BORDER_RIGHT] = new StaticBox(Vector2(1.35f, -0.95f), 0.01f, 2.8f);

	player = new DynamicBox(Vector2(PLAYER_X, PLAYER_Y), PLAYER_WIDTH, PLAYER_HEIGHT, Color(1,0,0));		

	collisionObjects[0] = player;

	ball = new Ball(Vector2( BALL_X, BALL_Y), BALL_WIDTH, BALL_HEIGHT);
	ball->setVelocity(Vector2(BALL_velocity_X, BALL_velocity_Y));	

	double currentFrame = renderer->getTime();
	double lastFrame = currentFrame;
	double deltaTime;
	countDownEnd = currentFrame + COUNTDOWN_START;
	
	Vector2 center = player->getCenter();

	// GameLoop
	while (renderer->getRunning())
	{	
		currentFrame = renderer->getTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		deltaTime = 0.0001f;

		// reset player velocity so hes not moving all the time without keypress
		player->setVelocity(Vector2(0.0f, 0.0f));

		if (renderer->getKey(GLFW_KEY_ESCAPE))
		{
			renderer->closeWindow();
		} 


		if (renderer->getKey(GLFW_KEY_R))
		{
			resetGame();
		} 

		if (currentFrame >= countDownEnd)
		{

			if (renderer->getKey(GLFW_KEY_LEFT))
			{
				player->setVelocity(Vector2(-2.0f, 0.0f));
			}

			if (renderer->getKey(GLFW_KEY_RIGHT))
			{
				player->setVelocity(Vector2(2.0f, 0.0f));	
			}

		}

		if (currentFrame >= countDownEnd)
		{
			player->Update(deltaTime);
			ball->Update(deltaTime);
			checkCollisions();
		}		

		renderer->preRender();

		renderer->renderObject(borders[BORDER_TOP]);
		renderer->renderObject(ball);
		renderer->renderObject(player);

		renderer->postRender();
		

	}

	// delete all gameobjects etc
	delete renderer;

	delete borders[BORDER_TOP];
	delete borders[BORDER_LEFT];
	delete borders[BORDER_BOTTOM];
	delete borders[BORDER_RIGHT];

	delete player;	
	delete ball;

	return 0;
}


