#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.h"
#include "Color.h"

// Realizes a StaticBox that can be rendered in 2D Space.
class StaticBox 
{

protected:
	Vector2 mOrigin;
	Color mColor; 
	float mHeight, mWidth;

public:
	// Returns the StaticBox of the object as Vector2.
	//
	// @return The current origin of the StaticBox.
	Vector2 getOrigin() const;

	// Sets the origin of the StaticBox.
	// The StaticBox will be teleported and not moved to the new origin.
	// 
	// @param newOrigin The new origin.
	void setOrigin(Vector2 newOrigin);

	// Returns the height of the StaticBox.
	//
	// @return The current height value.
	float getHeight() const;

	// Sets the height of the StaticBox.
	//
	// @param height The new height value.
	void setHeight(float height);

	// Returns the width of the StaticBox.
	//
	// @return The current width value.
	float getWidth() const;

	// Sets the width of the StaticBox.
	//
	// @param width The new width value.
	void setWidth(float width);

	// Returns the current Color of the StaticBox
	//
	// @return The current Color value.
	Color getColor() const;

	// Sets the current Color of the StaticBox.
	//
	// @param newColor The new Color.
	void setColor(Color newColor);

	// Returns the center of the object as Vector2.
	//
	// @return The current center of the StaticBox.
	Vector2 getCenter() const;

	StaticBox(Vector2 origin, float width, float height);
	StaticBox(Vector2 origin, float width, float height, Color c);

	virtual ~StaticBox(void);	
};


