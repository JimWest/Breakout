#include "stdafx.h"
#include "Breakout.h"


Breakout::Breakout(IRenderer *renderObject)
{
	renderer = renderObject;
	renderer->createWindow(RES_WIDTH, RES_HEIGHT, "Breakout");

	// create the player
	player = new DynamicBox(Vector2(PLAYER_X, PLAYER_Y), PLAYER_WIDTH, PLAYER_HEIGHT, Color(0.29f, 0.59f, 0.73f));		

	// create the ball
	ball = new DynamicBox(Vector2( BALL_X, BALL_Y), BALL_WIDTH, BALL_HEIGHT);
	ball->setVelocity(Vector2(BALL_velocity_X, BALL_velocity_Y));

	// create all the bricks
	for ( int n = 0, x = BRICK_PADDING_RIGHT, y = BRICKS_START_Y; n < BRICKS_AMOUNT; n++, x+=BRICK_WIDTH + BRICK_PADDING_RIGHT ) 
	{
		if ( x > (RES_WIDTH -  BRICK_WIDTH)) 
		{
			x = BRICK_PADDING_RIGHT;
			y += BRICK_HEIGHT + BRICK_PADDING_BOTTOM; 
		}

		Color brickCol = Color(0, 0.5f, 0.25f);

		if ( n%2 == 0 ) 
		{
			brickCol = Color(1, 1, 0);
		}


		bricks[n] = new Brick(Vector2(x, y), BRICK_WIDTH, BRICK_HEIGHT, brickCol, 1);
	}

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


		// Check KeyInput
		if (renderer->getKey(KeyR))
		{
			resetGame();
		} 

		if (currentFrame >= countDownEnd)
		{

			if (renderer->getKey(KeyLeft))
			{
				player->setVelocity(Vector2(-PLAYER_SPEED, 0.0f));
			}

			if (renderer->getKey(KeyRight))
			{
				player->setVelocity(Vector2(PLAYER_SPEED, 0.0f));	
			}

		}

		// Only update the ball etc. when the game has already started
		if (currentFrame >= countDownEnd)
		{
			player->Update(deltaTime);
			ball->Update(deltaTime);
			handleBallCollisions();
			checkPlayerBounds();
		}	

		// All the rendering stuff happens here
		renderer->preRender();

		// digit 3
		renderer->renderNumber(score % 1000 / 100 , SCORE_X, SCORE_Y);
		// digit 2
		renderer->renderNumber(score % 100 / 10 , SCORE_X + 40 , SCORE_Y);
		// digit 1
		renderer->renderNumber(score % 10, SCORE_X + 80, SCORE_Y);

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

bool Breakout::testAABB(const StaticBox &a, const StaticBox &b)
{
	if ( a.getOrigin().y + a.getHeight() < b.getOrigin().y ) return false; 
	else if ( a.getOrigin().y > b.getOrigin().y +  b.getHeight() ) return false;
	else if ( a.getOrigin().x + a.getWidth() < b.getOrigin().x ) return false; 
	else if ( a.getOrigin().x > b.getOrigin().x + b.getWidth() ) return false; 

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

	if (testAABB(*ball, *player)) 
	{
		// special collision with player
		Vector2 vel = ball->getVelocity();
		vel.y *= -1;

		if (ball->getCenter().x <= player->getCenter().x)
		{
			vel.x = -1 * MathUtility::abs(vel.x);
		}
		else
		{
			vel.x = MathUtility::abs(vel.x);
		}

		ball->setVelocity(vel);
	} 

	Vector2 ballOrigin = ball->getOrigin();

	// check collision for all bricks
	for ( int n = 0; n < BRICKS_AMOUNT; n++ ) 
	{
		if ( bricks[n]->getLife() > 0 ) 
		{
			if (testAABB(*ball, *bricks[n])) 
			{
				Vector2 vel = ball->getVelocity();

				if (ball->getOrigin().x + ball->getWidth() < bricks[n]->getOrigin().x || ball->getOrigin().x > bricks[n]->getOrigin().x + bricks[n]->getWidth())
				{
					vel.x *= -1;
				}
				else
				{
					vel.y *= -1;
				}

				ball->setVelocity(vel);
				bricks[n]->decLife();
				score ++;

				// max Score = 999 (only 3 digits)
				if (score > 999)
				{
					score = 999;
				}
				break; 
			}
		}
	}


	// Ball collision with the left side of the window
	if ( ballOrigin.x <= 0 )
	{
		Vector2 oldVel = ball->getVelocity();
		ball->setVelocity(Vector2(oldVel.x * -1, oldVel.y ));
	}

	// Ball collision with the right side of the window
	else if ( ballOrigin.x + ball->getWidth() >= RES_WIDTH )
	{
		Vector2 oldVel = ball->getVelocity();
		ball->setVelocity(Vector2(oldVel.x * -1, oldVel.y ));
	}

	// Ball collision with the top of the window
	if ( ballOrigin.y <= 0 )
	{
		Vector2 oldVel = ball->getVelocity();
		ball->setVelocity(Vector2(oldVel.x , oldVel.y * -1));
	}

	// Ball collision with the bottome of the window
	else if ( ballOrigin.y + ball->getWidth() > RES_HEIGHT ) 
	{		
		this->resetGame();
	}

}

void Breakout::resetGame()
{	
	player->setOrigin(Vector2(PLAYER_X, PLAYER_Y));
	ball->setOrigin(Vector2( BALL_X, BALL_Y));
	ball->setVelocity(Vector2(BALL_velocity_X, BALL_velocity_Y));

	double currentFrame = renderer->getTime();
	countDownEnd = renderer->getTime() + COUNTDOWN_START;

	for ( int n = 0; n < BRICKS_AMOUNT; n++ )
	{
		bricks[n]->setLife(1);
	}

	score = 0;

}

