#pragma once
#include "staticbox.h"
#include "Color.h"

class Brick :
	public StaticBox
{

protected:
	int life;   

public:	
	
	// Returns the current life.
	//
	// @return The current life.	
	int getLife() const;

	// Sets the value of the life property.
	//
	// @param life The new life value.
	
	void setLife(int life);
	
	Brick(Vector2 origin, float width, float height, Color c, int life);
	~Brick(void);

	// Decreases the current life by one.
    void decLife();
};


