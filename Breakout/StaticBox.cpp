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
	this->mOrigin = origin;	
	this->mHeight = height;
	this->mWidth= width;
	this->mColor = Color(1, 1, 1);
}

StaticBox::StaticBox(Vector2 origin, float width, float height, Color c)
{
	this->mOrigin = origin;		
	this->mHeight = height;
	this->mWidth= width;
	this->mColor = c;
}

StaticBox::~StaticBox(void)
{
}


void StaticBox::render()
{
	glPushMatrix();
	glTranslatef(this->getOrigin().x, this->getOrigin().y, 0);

	glColor3f(mColor.getR(), mColor.getG(), mColor.getB()); // (0.5, 0, 1) is half red and full blue, giving dark purple.

	glBegin(GL_POLYGON);	
		glVertex2f(0.0f, 0.0f);
		glVertex2f(mWidth, 0.0f);
		glVertex2f(mWidth, mHeight);
		glVertex2f(0.0f, mHeight);
	glEnd( );

	glPopMatrix();
}


