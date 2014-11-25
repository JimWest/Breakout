#pragma once
#include "Vector2.h"

class Entity
{

protected :
	Vector2 mOrigin;
	Vector2 mEndPoint;

public:
	Vector2 GetOrigin();
	void SetOrigin(Vector2 newOrigin);

	Vector2 GetEndPoint();
	void SetEndPoint(Vector2 newEndPoint);

	Entity(void);
	Entity(Vector2 origin, Vector2 endPoint);
	virtual ~Entity(void);
};

