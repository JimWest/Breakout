#include "stdafx.h"
#include "Breakout.h"


Breakout::Breakout(IRenderer* renderObject)
{
	renderer = renderObject;
	renderer->createWindow(RES_WIDTH, RES_HEIGHT);

	player = new DynamicBox(Vector2(PLAYER_X, PLAYER_Y), PLAYER_WIDTH, PLAYER_HEIGHT, Color(0.29f, 0.59f, 0.73f));		

	ball = new DynamicBox(Vector2( BALL_X, BALL_Y), BALL_WIDTH, BALL_HEIGHT);
	ball->setVelocity(Vector2(BALL_velocity_X, BALL_velocity_Y));

	for ( int n = 0, x = 4, y = 10; n < BRICKS_AMOUNT; n++, x+=66 ) 
    {
      if ( x > 560 ) 
        {
          x = 4;
          y += 25; 
        }

	  Color brickCol = Color(0, 0.5f, 0.25f);

	  if ( n%2 == 0 ) 
	  {
		  brickCol = Color(1, 1, 0);
	  }


	  bricks[n] = new Brick(Vector2(x, y), 60, 20, brickCol, 1);
    }

	double currentFrame = renderer->getTime();
	double lastFrame = currentFrame;
	double deltaTime;
	countDownEnd = currentFrame + COUNTDOWN_START;

	score = 0;
}


Breakout::~Breakout(void)
{
	delete player;	
	delete ball;

	for ( int n = 0; n < BRICKS_AMOUNT; n++ )
	{
		delete bricks[n];
	}
}



void Breakout::start()
{	
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
				player->setVelocity(Vector2(-PLAYER_SPEED, 0.0f));
			}

			if (renderer->getKey(GLFW_KEY_RIGHT))
			{
				player->setVelocity(Vector2(PLAYER_SPEED, 0.0f));	
			}

		}

		if (currentFrame >= countDownEnd)
		{
			player->Update(deltaTime);
			ball->Update(deltaTime);
			handleBallCollisions();
			checkPlayerBounds();
		}		


		renderer->preRender();
		renderer->renderObject(ball);
		renderer->renderObject(player);

		for ( int n = 0; n < BRICKS_AMOUNT; n++ )
		{
			if ( bricks[n]->getLife() > 0 ) 
			{
				renderer->renderObject(bricks[n]);
			}
		}

		renderer->postRender();
	}

}

bool Breakout::testAABB(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh)
{
  if ( Ay+Ah < By ) return false; 
  else if ( Ay > By+Bh ) return false;
  else if ( Ax+Aw < Bx ) return false; 
  else if ( Ax > Bx+Bw ) return false; 
 
  return true; 
}



void Breakout::checkPlayerBounds()
{
	
	if ( player->getOrigin().x < 0 ) 
    {			
		player->setOrigin(Vector2(0, player->getOrigin().y));
    }
 
	if ( player->getOrigin().x + player->getWidth() > RES_WIDTH ) 
    {
        player->setOrigin(Vector2(RES_WIDTH - player->getWidth(), player->getOrigin().y));
    }
}


void Breakout::handleBallCollisions()
{

	Collision playerCol = ball->getCollision(player);
	if (playerCol.colided)
	{
		//ball->bounceOff(playerCol);
	}

	Vector2 ballOrigin = ball->getOrigin();

	for ( int n = 0; n < BRICKS_AMOUNT; n++ ) 
	{
		if ( bricks[n]->getLife() > 0 ) 
		{
			if ( testAABB(ballOrigin.x, ballOrigin.y, ball->getWidth(), ball->getHeight(), 
				bricks[n]->getOrigin().x,bricks[n]->getOrigin().y, bricks[n]->getWidth(), bricks[n]->getHeight()) == true ) 
			{
				Vector2 oldVel = ball->getVelocity();
				ball->setVelocity(Vector2(oldVel.x * -1, oldVel.y));
				bricks[n]->decLife();
				score ++;
				break; 
			}
		}
	}


	for ( int n = 0; n < BRICKS_AMOUNT; n++ )
	{
		if ( bricks[n]->getLife() > 0 ) 
		{
			if ( testAABB(ballOrigin.x, ballOrigin.y, ball->getWidth(), ball->getHeight(), 
				bricks[n]->getOrigin().x,bricks[n]->getOrigin().y, bricks[n]->getWidth(), bricks[n]->getHeight()) == true ) 
			{
				Vector2 oldVel = ball->getVelocity();
				ball->setVelocity(Vector2(oldVel.x, oldVel.y * -1));
				bricks[n]->decLife();
				score ++ ;
				break;
			}
		}
	}

	if ( ballOrigin.x < 0 )
	{
		Vector2 oldVel = ball->getVelocity();
		ball->setVelocity(Vector2(oldVel.x * -1, oldVel.y ));
	}

	else if ( ballOrigin.x + ball->getWidth() > RES_WIDTH )
	{
		Vector2 oldVel = ball->getVelocity();
		ball->setVelocity(Vector2(oldVel.x * -1, oldVel.y ));
	}

	if ( ballOrigin.y < 0 )
	{
		Vector2 oldVel = ball->getVelocity();
		ball->setVelocity(Vector2(oldVel.x , oldVel.y * -1));
	}

	else if ( ballOrigin.y + ball->getWidth() > RES_HEIGHT ) //if the ball hit the bottom edge of screen
	{
		this->resetGame();
	}

	/*
	if ( testAABB(ballX,ballY,ballWH,ballWH,myX,myY,width,height) == true ) //if there is a collision between the ball and pad
	{
		vellY = -vellY; //change the ball's y velocity/speed
	}
	*/

}


void Breakout::resetGame()
{	
	player->setOrigin(Vector2(PLAYER_X, PLAYER_Y));
	ball->setOrigin(Vector2( BALL_X, BALL_Y));
	ball->setVelocity(Vector2(BALL_velocity_X, BALL_velocity_Y));

	double currentFrame = renderer->getTime();
	countDownEnd = renderer->getTime() + COUNTDOWN_START;

	for ( int n = 0; n < BRICKS_AMOUNT; n++ ) //A for loop that goes throught the array so we can set every bricks alive to true (not broken)
	{
		bricks[n]->setLife(1);
	}

	score = 0;

}

