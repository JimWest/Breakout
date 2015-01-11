#pragma once
#include "StaticBox.h"

class DynamicBox:
	public StaticBox

{
protected:
	Vector2 mForce;
	Vector2 mFriction;

public:
	Vector2 getForce() const;
	void setForce(Vector2 force);
	void setForce(float x, float y);

	Vector2 getFritction() const;
	void SetFriction(Vector2 force);
	void SetFriction(float x, float y);

	DynamicBox(void);
	DynamicBox(Vector2 origin, float width, float height);
	~DynamicBox(void);

	virtual void Update(double deltaTime);
	virtual void move(Vector2 moveVector);
};

