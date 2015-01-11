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

	if (col.xAxis)
	{
		this->setForce(oldForce.x * -1, oldForce.y);		

		if (col.collisionPoint.x > this->getOrigin().x)
		{
			newBallOrigin.x = col.collisionPoint.x - this->getWidth();
		}
		else
		{
			newBallOrigin.x = col.collisionPoint.x;
		}

	}
	else
	{
		this->setForce(oldForce.x, oldForce.y * -1);

		if (col.collisionPoint.y > this->getOrigin().y)
		{
			newBallOrigin.y = col.collisionPoint.y - this->getHeight();
		}
		else
		{
			newBallOrigin.y = col.collisionPoint.y;
		}
	}

	this->setOrigin(newBallOrigin);
	
}