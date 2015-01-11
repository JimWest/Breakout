#pragma once
#include "Vector2.h"

struct Collision {
  bool colided;
  bool xAxis;
  Vector2 collisionPoint;
} ;

class StaticBox 
{

protected:
	Vector2 mOrigin;
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
	virtual ~StaticBox(void);
	
	virtual void render();
	virtual Collision getCollision(StaticBox* otherStaticBox);
};

