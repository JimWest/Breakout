#include "StdAfx.h"
#include "Entity.h"
#include <GLFW/glfw3.h>


Vector2 Entity::getOrigin()
{
	return this->mOrigin;
}

void Entity::setOrigin(Vector2 newOrigin)
{
	this->mOrigin = newOrigin;
}

Entity::Entity(void)
{
	this->setOrigin(*new Vector2);
}

Entity::Entity(Vector2 origin)
{
	this->setOrigin(origin);	
}

Entity::~Entity(void)
{
}

void Entity::move(Vector2 moveVector)
{
	//Vector2 newOrigin = this->getOrigin() + moveVector;
	this->setOrigin(this->getOrigin() + moveVector);
}


