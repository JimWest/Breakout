#pragma once
#include "StaticBox.h"

class DynamicBox:
	public StaticBox

{
protected:
	Vector2 mVelocity;

public:
	Vector2 getVelocity() const;
	void setVelocity(Vector2 velocity);

	DynamicBox(void);
	DynamicBox(Vector2 origin, float width, float height);
	DynamicBox(Vector2 origin, float width, float height, Color c);

	~DynamicBox(void);

	virtual void Update(float deltaTime);
	virtual void move(Vector2 moveVector);

	virtual Collision getCollision(StaticBox* otherStaticBox);
};

