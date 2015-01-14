#include "StdAfx.h"
#include "Ball.h"


Ball::Ball(void):DynamicBox()
{
}

Ball::Ball(Vector2 origin, float width, float height):DynamicBox(origin, width, height)
{	
}


Ball::~Ball(void)
{	
}

void Ball::bounceOff(Collision col)
{
	Vector2 oldvelocity = this->getVelocity();
	Vector2 newBallOrigin = this->getOrigin();

	if (col.orientation == TOP)
	{
		this->setVelocity(Vector2(oldvelocity.x, oldvelocity.y  * -1));
		newBallOrigin.y = col.collisionPoint.y - this->getHeight();
	}
	else if (col.orientation == RIGHT)
	{
		this->setVelocity(Vector2(oldvelocity.x * -1, oldvelocity.y));
		newBallOrigin.x = col.collisionPoint.x - this->getWidth();
	}
	else if (col.orientation == BOTTOM)
	{
		this->setVelocity(Vector2(oldvelocity.x, oldvelocity.y  * -1));
		newBallOrigin.y = col.collisionPoint.y;
	}
	else if (col.orientation == LEFT)
	{
		this->setVelocity(Vector2(oldvelocity.x * -1, oldvelocity.y));
		newBallOrigin.x = col.collisionPoint.x;
	}
	

	this->setOrigin(newBallOrigin);
	
}