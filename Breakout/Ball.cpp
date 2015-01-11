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
	//if (col.collisionPoint
	//newBallOrigin.x = borders[BORDER_LEFT]->getOrigin().x;
	
	Vector2 oldForce = this->getForce();
	Vector2 newBallOrigin = this->getOrigin();

	if (col.orientation == TOP)
	{
		this->setForce(oldForce.x, oldForce.y  * -1);
		newBallOrigin.y = col.collisionPoint.y - this->getHeight();
	}
	else if (col.orientation == RIGHT)
	{
		this->setForce(oldForce.x * -1, oldForce.y);
		newBallOrigin.x = col.collisionPoint.x - this->getWidth();
	}
	else if (col.orientation == BOTTOM)
	{
		this->setForce(oldForce.x, oldForce.y  * -1);
		newBallOrigin.y = col.collisionPoint.y;
	}
	else if (col.orientation == LEFT)
	{
		this->setForce(oldForce.x * -1, oldForce.y);
		newBallOrigin.x = col.collisionPoint.x;
	}
	

	this->setOrigin(newBallOrigin);
	
}