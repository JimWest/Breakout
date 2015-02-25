#include "StdAfx.h"
#include "StaticBox.h"

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

Color  StaticBox::getColor() const
{
	return this->mColor;
}
	
void  StaticBox::setColor(Color newColor)
{
	this->mColor = newColor;
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


