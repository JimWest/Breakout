#pragma once
#include "Vector2.h"
#include "entity.h"

class Rect :
	public Entity
{
public:
	Rect(void);
	Rect(Vector2 origin, Vector2 endPoint);
	virtual ~Rect(void);
	
	virtual void Render();
	virtual void Update();
};

