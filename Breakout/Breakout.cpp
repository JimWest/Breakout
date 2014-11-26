#include "stdafx.h"
#include "GameWindow.h"
#include "GameWindow.h"
#include "Entity.h"
#include "Rect.h"
#include "Ball.h"

#define RES_WIDTH	800
#define RES_HEIGHT	600

#define BOTTOM_BORDER	25

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

Rect* player;
Ball* ball;
Rect* borders [4];
Rect* collisionObjects[99];


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	} 

	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		Vector2 origin = player->GetOrigin();
		Vector2 newOrigin = player->GetOrigin() + Vector2(-0.1f, 0);

		if (newOrigin.x < borders[BORDER_LEFT]->GetOrigin().x)
		{
			newOrigin.x = borders[BORDER_LEFT]->GetOrigin().x;
		}

		player->SetOrigin(newOrigin);
	}

	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		Vector2 origin = player->GetOrigin();
		Vector2 newOrigin = player->GetOrigin() + Vector2(0.1f, 0);

		if (newOrigin.x + player->GetWidth() > borders[BORDER_RIGHT]->GetOrigin().x)
		{
			newOrigin.x = borders[BORDER_RIGHT]->GetOrigin().x - player->GetWidth() ;
		}

		player->SetOrigin(newOrigin);		
	}



}


int main(void)
{		
	// Init main OpenGL Window
	GameWindow *gameWindow = new GameWindow(RES_WIDTH, RES_HEIGHT);
	glfwSetKeyCallback(gameWindow->getWindow(), key_callback);

	// Init all game objects

	borders[BORDER_TOP] = new Rect(Vector2(-1.4, 0.8f), 2.8f, 0.01f);
	borders[BORDER_LEFT] = new Rect(Vector2(-1.35, -0.95f), 0.01f, 2.8f);
	borders[BORDER_BOTTOM] = new Rect(Vector2(-1.4, -1),2.8f, 0.01f);
	borders[BORDER_RIGHT] = new Rect(Vector2(1.35, 0.95f), 0.01f, -2.8f);

	player = new Rect(Vector2(PLAYER_X, PLAYER_Y), PLAYER_WIDTH, PLAYER_HEIGHT);		
	ball = new Ball(Vector2( BALL_X, BALL_Y), BALL_WIDTH, BALL_HEIGHT, Vector2(BALL_FORCE_X, BALL_FORCE_Y));

	double currentFrame = glfwGetTime();
	double lastFrame = currentFrame;
	double deltaTime;
	// GameLoop
	while (gameWindow->getRunning())
	{
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClear(GL_COLOR_BUFFER_BIT);

		ball->Update(deltaTime);
		Vector2 newBallOrigin = ball->GetOrigin();

		if(newBallOrigin.y - ball->GetHeight() < player->GetOrigin().y)
		{
			newBallOrigin.y = player->GetOrigin().y + ball->GetHeight();
			ball->BounceOff(false);
		}

		if (newBallOrigin.x < borders[BORDER_LEFT]->GetOrigin().x)
		{
			newBallOrigin.x = borders[BORDER_LEFT]->GetOrigin().x;
			ball->BounceOff(true);
		} else if (newBallOrigin.x + ball->GetWidth() > borders[BORDER_RIGHT]->GetOrigin().x)
		{
			newBallOrigin.x = borders[BORDER_RIGHT]->GetOrigin().x - ball->GetWidth();
			ball->BounceOff(true);
		}

		if (newBallOrigin.y +  ball->GetHeight() > borders[BORDER_TOP]->GetOrigin().y)
		{
			newBallOrigin.y = borders[BORDER_TOP]->GetOrigin().y - ball->GetHeight();
			ball->BounceOff(false);
		}
		else if (newBallOrigin.y < borders[BORDER_BOTTOM]->GetOrigin().y)
		{
			newBallOrigin.y = borders[BORDER_BOTTOM]->GetOrigin().y;
			ball->BounceOff(false);
		}
		

		ball->SetOrigin(newBallOrigin);

		borders[BORDER_TOP]->Render();
		borders[BORDER_BOTTOM]->Render();
		ball->Render();
		player->Render();		

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


