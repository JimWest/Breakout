#pragma once
#include "Vector2.h"
#include "Color.h"

enum Orientation  {TOP, RIGHT, BOTTOM, LEFT};

struct Collision {
  bool colided;
  Orientation orientation;
  Vector2 collisionPoint;
} ;

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

	Vector2 getCenter() const;

	StaticBox(void);
	StaticBox(Vector2 origin, float width, float height);
	StaticBox(Vector2 origin, float width, float height, Color c);

	virtual ~StaticBox(void);	
	virtual void render();
};


