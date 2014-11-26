#pragma once
#include "Vector2.h"
#include "entity.h"

class Rect :
	public Entity
{

protected:
	float mHeight, mWidth;

public:
	
	float GetHeight();
	void SetHeight(float height);

	float GetWidth();
	void SetWidth(float width);

	Rect(void);
	Rect(Vector2 origin, float width, float height);
	virtual ~Rect(void);
	
	virtual void Render();
	virtual void Update(double deltaTime);

	virtual void Move(Vector2 moveVector);
	virtual bool GetIntersects(Rect* otherRect);
};

