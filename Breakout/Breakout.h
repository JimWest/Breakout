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

// Class for the Game Breakout
// "A ball travels across the screen, bouncing off the top and side walls of the screen. 
// When a brick is hit, the ball bounces away and the brick is destroyed. 
// The player loses a turn when the ball touches the bottom of the screen. 
// To prevent this from happening, the player has a movable paddle to bounce the ball upward, keeping it in play."
// - Wikipedia, http://en.wikipedia.org/wiki/Breakout_(video_game)
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

	// AABB -  Axis-Aligned Bounding Boxes
	// Algorithm to detect simple 2D Colloision (no rotation, only rectangles).
	//
	// @return True, if the two bodys colide with eachother.
	bool testAABB(const StaticBox &a, const StaticBox &b);

	// Handles all the collisions of the ball 
	// (ball - wall, ball - player, ball - brick).
	//
	// Changes the velocity of the ball if a collision occurs.
	// Also checks if the ball touched the bottom bound and resets the game.
	void handleBallCollisions();	

	// Checks if the player is in between the bounds of the window and moves the 
	// player back if he moves out of bounds.
	void checkPlayerBounds();

public:
	// Constructor for the Breakout game object.
	// Creates all the objects needed to start the game.
	//
	// @param renderer Object to render primitives.
	Breakout(IRenderer* renderer);

	// Default constructor.
	~Breakout(void);
	
	// Starts the game and its main loop,
	// will only terminate if the game exits.
	virtual void start();

	
	// Resets the game back to the starting conditions
	// - countdown timer, velocity, bricks, player.
	// Will start directly a new game.
	virtual void resetGame();
};

