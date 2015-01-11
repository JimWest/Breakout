#include "StdAfx.h"
#include "DynamicBox.h"



Vector2 DynamicBox::getForce() const
{
	return this->mForce;
}

void DynamicBox::setForce(Vector2 force)
{	
	mForce = force;
}

void DynamicBox::setForce(float x, float y)
{
	mForce.x = x;
	mForce.y = y;
}

Vector2 DynamicBox::getFritction() const
{
	return this->mFriction;
}

void DynamicBox::SetFriction(Vector2 force)
{	
	mFriction.x = force.x;
	mFriction.y = force.y;
}

void DynamicBox::SetFriction(float x, float y)
{
	mFriction.x = x;
	mFriction.y = y;
}


DynamicBox::DynamicBox(void):StaticBox()
{
}


DynamicBox::DynamicBox(Vector2 origin, float width, float height):StaticBox(origin, width, height)
{
}



DynamicBox::~DynamicBox(void)
{
}


void DynamicBox::Update(double deltaTime)
{
	if (mForce.x != 0 || mForce.y != 0)
	{		
		this->move(this->getForce()* deltaTime);
	}
}

void DynamicBox::move(Vector2 moveVector)
{
	//Vector2 newOrigin = this->getOrigin() + moveVector;
	this->setOrigin(this->getOrigin() + moveVector);
}

