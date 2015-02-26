#pragma once
#include "StaticBox.h"

class DynamicBox:
	public StaticBox

{
protected:
	Vector2 mVelocity;

public:
	// Returns the current velocity of the DynamicBox.
	//
	// @return The Vector2 velocity object.	
	Vector2 getVelocity() const;

	// Sets the velocity.
	//
	// @param velocity The new velocity Vector.	
	void setVelocity(Vector2 velocity);

	DynamicBox(Vector2 origin, float width, float height);
	DynamicBox(Vector2 origin, float width, float height, Color c);

	~DynamicBox(void);

	// Updates the current position based on the current velocity,
	// deltaTime and the old position.
	virtual void Update(float deltaTime);

	// Moves the DynamicBox by the given moveVector.
	// 
	// @param moveVector The vector by which the player should be moved with.
	virtual void move(Vector2 moveVector);
};

