#include "StdAfx.h"
#include "DynamicBox.h"


Vector2 DynamicBox::getVelocity() const
{
	return this->mVelocity;
}

void DynamicBox::setVelocity(Vector2 velocity)
{	
	mVelocity = velocity;
}


DynamicBox::DynamicBox(Vector2 origin, float width, float height):StaticBox(origin, width, height)
{
}

DynamicBox::DynamicBox(Vector2 origin, float width, float height, Color c):StaticBox(origin, width, height, c)
{
}


DynamicBox::~DynamicBox(void)
{
}


void DynamicBox::Update(float deltaTime)
{
	if (mVelocity.x != 0 || mVelocity.y != 0)
	{		
		this->move(this->getVelocity()* deltaTime);		
	}
}

void DynamicBox::move(Vector2 moveVector)
{
	this->setOrigin(this->getOrigin() + moveVector);
}

