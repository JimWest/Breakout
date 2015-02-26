#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.h"
#include "Color.h"


class StaticBox 
{

protected:
	Vector2 mOrigin;
	Color mColor; 
	float mHeight, mWidth;

public:
	Vector2 getOrigin() const;
	void setOrigin(Vector2 newOrigin);
	
	float getHeight() const;
	void setHeight(float height);

	float getWidth() const;
	void setWidth(float width);

	Color getColor() const;
	void setColor(Color newColor);

	Vector2 getCenter() const;

	StaticBox(Vector2 origin, float width, float height);
	StaticBox(Vector2 origin, float width, float height, Color c);

	virtual ~StaticBox(void);	
};


