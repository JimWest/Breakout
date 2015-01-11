#pragma once
#include "Vector2.h"
#include "DynamicBox.h"

class Ball:
		public DynamicBox
{
public:
	
	Ball(void);
	Ball(Vector2 origin, float width, float height);
	~Ball(void);
		
	void bounceOff(Collision col);
	
};

