#include "StdAfx.h"
#include "StaticBox.h"
#include <GLFW/glfw3.h>
#include "MathUtility.h"

Vector2 StaticBox::getOrigin() const
{
	return this->mOrigin;
}

void StaticBox::setOrigin(Vector2 newOrigin)
{
	this->mOrigin = newOrigin;
}


float StaticBox::getHeight() const
{
	return this->mHeight;
}

void StaticBox::setHeight(float height)
{
	this->mHeight = height;
}

float StaticBox::getWidth() const
{
	return this->mWidth;
}

void StaticBox::setWidth(float width)
{
	this->mWidth = width;
}

StaticBox::StaticBox(void)
{
	this->mHeight = 0;
	this->mWidth= 0;
}

Vector2 StaticBox::getCenter() const
{
	Vector2 origin = this->getOrigin();
	return (origin + Vector2(origin.x + this->getWidth(), origin.y + this->getHeight())) / 2;
}

StaticBox::StaticBox(Vector2 origin, float width, float height)
{
	this->setOrigin(origin);	
	this->mHeight = height;
	this->mWidth= width;
}

StaticBox::~StaticBox(void)
{
}


void StaticBox::render()
{
	glPushMatrix();
	glTranslatef(this->getOrigin().x, this->getOrigin().y, 0);

	glBegin(GL_POLYGON);	
	glVertex2f(0.0f, 0.0f);
	glVertex2f(mWidth, 0.0f);
	glVertex2f(mWidth, mHeight);
	glVertex2f(0.0f, mHeight);
	glEnd( );

	glPopMatrix();
}


// checks if the object collides with another given object
Collision StaticBox::getCollision(StaticBox* otherStaticBox)
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
			Vector2 deltaCenter = otherStaticBox->getCenter() - this->getCenter();
			int a = 1;

			if ((origin.y + this->getHeight()) < (otherOrigin.y + otherStaticBox->getHeight()) && (origin.y > otherOrigin.y))
			{
				// y-collision
				col.xAxis = false;
				if (deltaCenter.x > 0 )
				{
					// right
					col.collisionPoint = Vector2(origin.x +  (this->getWidth() / 2), origin.y);
				}
				else
				{
					// left
					col.collisionPoint = Vector2(origin.x -  (this->getWidth() / 2), origin.y);
				}

			} else 
			{
				// x-collision
				col.xAxis = true;
				if (deltaCenter.y > 0 )
				{
					// below
					col.collisionPoint = Vector2(origin.x, origin.y - (this->getHeight() / 2));
				}
				else
				{
					// above
					col.collisionPoint = Vector2(origin.x, origin.y + (this->getHeight() / 2));
				}
			}


		}
	}

	return col;
}