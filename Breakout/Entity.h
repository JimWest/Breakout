#pragma once
#include "Vector2.h"

class Entity
{

protected :
	Vector2 mOrigin;

public:
	Vector2 GetOrigin();
	void SetOrigin(Vector2 newOrigin);

	Entity(void);
	Entity(Vector2 origin);
	virtual ~Entity(void);
};

