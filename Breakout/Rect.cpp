#include "StdAfx.h"
#include "Rect.h"
#include <GLFW/glfw3.h>

float Rect::GetHeight()
{
	return this->mHeight;
}

void Rect::SetHeight(float height)
{
	this->mHeight = height;
}

float Rect::GetWidth()
{
	return this->mWidth;
}

void Rect::SetWidth(float width)
{
	this->mWidth = width;
}

Rect::Rect(void):Entity()
{
	this->mHeight = 0;
	this->mWidth= 0;
}

Rect::Rect(Vector2 origin, float width, float height):Entity(origin)
{
	this->mHeight = height;
	this->mWidth= width;
}

Rect::~Rect(void)
{
}


void Rect::Render()
{
	glPushMatrix();
	glTranslatef(this->mOrigin.x, this->mOrigin.y, 0);

	glBegin(GL_POLYGON);	
		glVertex2f(0.0f, 0.0f);
		glVertex2f(mWidth, 0.0f);
		glVertex2f(mWidth, mHeight);
		glVertex2f(0.0f, mHeight);
	glEnd( );

	glPopMatrix();
}

void Rect::Update(double deltaTime)
{
}

void Rect::Move(Vector2 moveVector)
{
	Vector2 newOrigin = this->GetOrigin() + moveVector;
	this->SetOrigin(newOrigin);
}

bool Rect::GetIntersects(Rect* otherRect)
{
	Vector2 otherOrigin = otherRect->GetOrigin();
	float otherHeight = otherRect->GetHeight();
	float otherWidth = otherRect->GetWidth();

	return false;
}
