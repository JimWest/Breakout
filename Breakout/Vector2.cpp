#include "StdAfx.h"
#include "Vector2.h"


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


Vector2 &Vector2::operator+(Vector2 summand)
{
	this->x+= summand.x;
	this->y+= summand.y;
    return *this;
}

Vector2 &Vector2::operator-(Vector2 summand)
{
	this->x-= summand.x;
	this->y-= summand.y;
    return *this;
}

Vector2 &Vector2::operator*(float multiplikator)
{
	this->x*= multiplikator;
	this->y*= multiplikator;
    return *this;
}

Vector2 &Vector2::operator/(float multiplikator)
{
	this->x/= multiplikator;
	this->y/= multiplikator;
    return *this;
}



