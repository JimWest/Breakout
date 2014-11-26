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

Entity::Entity(void)
{
	this->SetOrigin(*new Vector2);
}

Entity::Entity(Vector2 origin)
{
	this->SetOrigin(origin);	
}

Entity::~Entity(void)
{
}


