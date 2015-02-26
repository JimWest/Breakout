#pragma once
#include "game.h"
#include "StaticBox.h"
#include "DynamicBox.h"
#include "Brick.h"

#include <iostream>
#include <string>

#include "IRenderer.h"
#include "OpenGLRenderer.h"
#include "MathUtility.h"
#include "KeyInput.h"

#define RES_WIDTH	600
#define RES_HEIGHT	600

#define COUNTDOWN_START	3

#define SCORE_X		10
#define SCORE_Y		10

#define BRICKS_AMOUNT 45
#define BRICKS_START_Y 60 
#define BRICK_WIDTH 60
#define BRICK_HEIGHT 20
#define BRICK_PADDING_RIGHT 6
#define BRICK_PADDING_BOTTOM 6

#define BALL_X	400
#define BALL_Y	430
#define BALL_HEIGHT	15
#define BALL_WIDTH	15

#define BALL_velocity_X	-120
#define BALL_velocity_Y	120

#define PLAYER_X	300
#define PLAYER_Y	500
#define PLAYER_WIDTH	80
#define PLAYER_HEIGHT	20
#define PLAYER_SPEED 240

class Breakout :
	public Game
{
private:	
	IRenderer *renderer;
	DynamicBox *player;
	DynamicBox *ball;
	Brick *bricks[BRICKS_AMOUNT];	

	int score;
	double countDownEnd;

	bool testAABB(const StaticBox &a, const StaticBox &b);
	void handleBallCollisions();
	void checkPlayerBounds();

public:
	Breakout(IRenderer* renderer);
	~Breakout(void);

	virtual void start();
	virtual void resetGame();
};

