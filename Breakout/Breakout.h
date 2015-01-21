#pragma once
#include "game.h"
#include "StaticBox.h"
#include "DynamicBox.h"
#include "Brick.h"

#include <iostream>
#include <string>

#include "IRenderer.h"
#include "OpenGLRenderer.h"

#define RES_WIDTH	600
#define RES_HEIGHT	400

#define COUNTDOWN_START	3

#define BORDER_LEFT	0
#define BORDER_RIGHT	1
#define BORDER_TOP	2
#define BORDER_BOTTOM	3

#define BORDER_RES_WIDTH	100

#define PLAYER_X	300
#define PLAYER_Y	370
#define PLAYER_WIDTH	80
#define PLAYER_HEIGHT	20
#define PLAYER_SPEED 240

#define BALL_X	400
#define BALL_Y	300
#define BALL_HEIGHT	20
#define BALL_WIDTH	20

#define BALL_velocity_X	-120
#define BALL_velocity_Y	120

#define BRICKS_AMOUNT 45

class Breakout :
	public Game
{
private:	
	IRenderer* renderer;
	DynamicBox* player;
	DynamicBox* ball;
	Brick* bricks[BRICKS_AMOUNT];	

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

