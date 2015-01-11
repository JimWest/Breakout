#include "stdafx.h"
#include "GameWindow.h"
#include "GameWindow.h"
#include "StaticBox.h"
#include "DynamicBox.h"
#include "StaticBox.h"
#include "Ball.h"

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
#define BALL_FORCE_X	1
#define BALL_FORCE_Y	1

StaticBox* player;
Ball* ball;
StaticBox* borders [4];
StaticBox* collisionObjects[99];
double countDownEnd;

void resetGame()
{	
	player->setOrigin(Vector2(PLAYER_X, PLAYER_Y));
	ball->setOrigin(Vector2( BALL_X, BALL_Y));
	ball->setForce(BALL_FORCE_X, BALL_FORCE_Y);

	double currentFrame = glfwGetTime();
	countDownEnd = glfwGetTime() + COUNTDOWN_START;

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	} 

	if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		resetGame();
	} 

	if (glfwGetTime() >= countDownEnd)
	{

		if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			Vector2 origin = player->getOrigin();
			Vector2 newOrigin = player->getOrigin() + Vector2(-0.1f, 0);

			if (newOrigin.x < borders[BORDER_LEFT]->getOrigin().x)
			{
				newOrigin.x = borders[BORDER_LEFT]->getOrigin().x;
			}

			player->setOrigin(newOrigin);
		}

		if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			Vector2 origin = player->getOrigin();
			Vector2 newOrigin = player->getOrigin() + Vector2(0.1f, 0);

			if (newOrigin.x + player->getWidth() > borders[BORDER_RIGHT]->getOrigin().x)
			{
				newOrigin.x = borders[BORDER_RIGHT]->getOrigin().x - player->getWidth() ;
			}

			player->setOrigin(newOrigin);		
		}

	}

}



void checkCollisions()
{
	/*Vector2 newBallOrigin = ball->getOrigin();

	// player - ball collision
	if(newBallOrigin.y - ball->getHeight() < player->getOrigin().y 
		&& (newBallOrigin.x >= player->getOrigin().x && newBallOrigin.x + ball->getWidth() <= player->getOrigin().x + player->getWidth()))
	{

		Collision col = ball->getCollision(player);
		newBallOrigin.y = player->getOrigin().y + ball->getHeight();

		ball->bounceOff(col);
		ball->setOrigin(newBallOrigin);
	}

	*/

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
	
	for (int i = 0; i<3; i++)
	{
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
	// Init main OpenGL Window
	GameWindow *gameWindow = new GameWindow(RES_WIDTH, RES_HEIGHT);
	glfwSetKeyCallback(gameWindow->getWindow(), key_callback);

	// Init all game objects

	borders[BORDER_TOP] = new StaticBox(Vector2(-1.4, 0.8f), 2.8f, 0.01f);
	borders[BORDER_LEFT] = new StaticBox(Vector2(-1.35, -0.95f), 0.01f, 2.8f);
	borders[BORDER_BOTTOM] = new StaticBox(Vector2(-1.4, -1),2.8f, 0.01f);
	borders[BORDER_RIGHT] = new StaticBox(Vector2(1.30, -0.95f), 2, 2.8f);

	player = new StaticBox(Vector2(PLAYER_X, PLAYER_Y), PLAYER_WIDTH, PLAYER_HEIGHT);		

	collisionObjects[0] = player;

	ball = new Ball(Vector2( BALL_X, BALL_Y), BALL_WIDTH, BALL_HEIGHT);
	ball->setForce(Vector2(BALL_FORCE_X, BALL_FORCE_Y));	

	double currentFrame = glfwGetTime();
	double lastFrame = currentFrame;
	double deltaTime;
	countDownEnd = currentFrame + COUNTDOWN_START;
	
	Vector2 center = player->getCenter();

	// GameLoop
	while (gameWindow->getRunning())
	{
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClear(GL_COLOR_BUFFER_BIT);

		if (currentFrame >= countDownEnd)
		{
			ball->Update(0.0001f);
			checkCollisions();
		}		

		borders[BORDER_TOP]->render();
		borders[BORDER_BOTTOM]->render();
		borders[BORDER_LEFT]->render();
		borders[BORDER_RIGHT]->render();

		ball->render();
		player->render();		

		glfwSwapBuffers(gameWindow->getWindow());
		glfwPollEvents();
	}

	// delete all gameobjects etc
	delete gameWindow;

	delete borders[BORDER_TOP];
	delete borders[BORDER_LEFT];
	delete borders[BORDER_BOTTOM];
	delete borders[BORDER_RIGHT];

	delete player;	
	delete ball;

	return 0;
}


