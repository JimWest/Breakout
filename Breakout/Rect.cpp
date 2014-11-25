#include "StdAfx.h"
#include "Rect.h"
#include <GLFW/glfw3.h>


Rect::Rect(void)
{
	this->SetOrigin(*new Vector2);
	this->SetEndPoint(*new Vector2);	
}

Rect::Rect(Vector2 origin, Vector2 endPoint)
{
	this->SetOrigin(origin);
	this->SetEndPoint(endPoint);			
}

Rect::~Rect(void)
{
}


void Rect::Render()
{
	glBegin(GL_POLYGON);	
	glVertex2f( mOrigin.x, mOrigin.y );
	glVertex2f( mEndPoint.x, mOrigin.y );
	glVertex2f( mEndPoint.x, mEndPoint.y );
	glVertex2f( mOrigin.x, mEndPoint.y );
	glEnd( );
}

void Rect::Update()
{
}
