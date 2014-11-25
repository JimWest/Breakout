#include "StdAfx.h"
#include "Entity.h"
#include <GLFW/glfw3.h>


Vector2 Entity::GetOrigin()
{
	return this->mOrigin;
}

void Entity::SetOrigin(Vector2 newOrigin)
{
	this->mOrigin = newOrigin;
}

Vector2 Entity::GetEndPoint()
{
	return this->mEndPoint;
}

void Entity::SetEndPoint(Vector2 newEndPoint)
{
	this->mEndPoint = newEndPoint;
}


Entity::Entity(void)
{
	this->SetOrigin(*new Vector2);
	this->SetEndPoint(*new Vector2);	
}

Entity::Entity(Vector2 origin, Vector2 endPoint)
{
	this->SetOrigin(origin);
	this->SetEndPoint(endPoint);			
}

Entity::~Entity(void)
{
}


