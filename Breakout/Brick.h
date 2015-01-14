#pragma once
#include "staticbox.h"
#include "Color.h"

class Brick :
	public StaticBox
{

protected:
	int life;   

public:	
	void setLife(int life);
    int getLife();

	Brick(void);
	Brick(Vector2 origin, float width, float height, Color c, int life);
	~Brick(void);

    void decLife();
};


