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


DynamicBox::DynamicBox(void):StaticBox()
{
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
	//Vector2 newOrigin = this->getOrigin() + moveVector;
	this->setOrigin(this->getOrigin() + moveVector);
}

// checks if the object collides with another given object
Collision DynamicBox::getCollision(StaticBox* otherStaticBox)
{
	Collision col;	
	col.colided = false;
	//col.collisionPoint

	Vector2 origin = this->getOrigin();
	Vector2 otherOrigin = otherStaticBox->getOrigin();
	float otherHeight = otherStaticBox->getHeight();
	float otherWidth = otherStaticBox->getWidth();

	// check xAxis 
	if ((origin.x + this->getWidth() >= otherOrigin.x && origin.x <= otherOrigin.x + otherWidth) 
		|| (origin.x <= otherOrigin.x + otherWidth && origin.x + this->getWidth() >= otherOrigin.x))
	{
		// check yAxis
		if ((origin.y + this->getHeight() >= otherOrigin.y && origin.y  <= otherOrigin.y + otherHeight)
			|| (origin.y <= otherOrigin.y + otherHeight && origin.y + this->getHeight() >= otherOrigin.y))
		{
			// Objects collided
			col.colided = true;
						

			if (origin.y <= otherOrigin.y && mVelocity.y > 0)
			{
				col.orientation = TOP;
				col.collisionPoint = Vector2(origin.x, origin.y + (this->getHeight()));
			} 
			else if (origin.x <= otherOrigin.x && mVelocity.x > 0)
			{
				col.orientation = RIGHT;
				col.collisionPoint = Vector2(origin.x +  (this->getWidth()), origin.y);
			}
			else if (origin.x >= otherOrigin.x && mVelocity.x < 0)
			{
				col.orientation = LEFT;
				col.collisionPoint = Vector2(origin.x, origin.y);
			}
			//else if (origin.y >= otherOrigin.y  && mVelocity.y < 0)
			//{			
			else
			{
				col.orientation = BOTTOM;
				col.collisionPoint = Vector2(origin.x, origin.y);
			}		

		}
	}

	return col;
}

