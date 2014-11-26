#include "StdAfx.h"
#include "Ball.h"


Vector2 Ball::GetForce() const
{
	return this->mForce;
}
void Ball::SetForce(Vector2 force)
{
	this->mForce = force;
}

Ball::Ball(void):Rect()
{
	this->mForce = Vector2();
}

Ball::Ball(Vector2 origin, float width, float height, Vector2 force):Rect(origin, width, height)
{
	this->mForce = force;
}


Ball::~Ball(void)
{
}

void Ball::Update(double deltaTime)
{
	if (mForce.x != 0 || mForce.y != 0)
	{
		Vector2 force = mForce;
		this->Move(force * deltaTime);
	}
}

void Ball::BounceOff(bool xAxis)
{
	if (xAxis)
	{
		mForce = Vector2(mForce.x *-1, mForce.y);
	}
	else
	{
		mForce = Vector2(mForce.x, mForce.y*-1);	
	}
	
}

/*

// Find the length of the component of each of the movement
// vectors along n. 
// a1 = v1 . n
// a2 = v2 . n
float a1 = v1.dot(n);
float a2 = v2.dot(n);

// Using the optimized version, 
// optimizedP =  2(a1 - a2)
float optimizedP = (2.0 * (a1 - a2)) / 2;

// Calculate v1', the new movement vector of circle1
// v1' = v1 - optimizedP * n
Vector v1' = v1 - optimizedP *  n;

// Calculate v1', the new movement vector of circle1
// v2' = v2 + optimizedP * n
Vector v2' = v2 + optimizedP * n;
*/