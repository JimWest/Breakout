#pragma once
#include "Vector2.h"

class Entity
{

protected :
	Vector2 mOrigin;

public:
	Vector2 getOrigin();
	void setOrigin(Vector2 newOrigin);

	Entity(void);
	Entity(Vector2 origin);
	virtual ~Entity(void);

	virtual void move(Vector2 moveVector);
};

