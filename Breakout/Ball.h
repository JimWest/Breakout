#pragma once
#include "Vector2.h"
#include "rect.h"

class Ball:
		public Rect
{
protected:
	Vector2 mForce;

public:
	Vector2 GetForce() const;
	void SetForce(Vector2 force);

	Ball(void);
	Ball(Vector2 origin, float width, float height, Vector2 force);
	~Ball(void);

	virtual void Update(double deltaTime);
	void BounceOff(bool xAxis);
	
};

