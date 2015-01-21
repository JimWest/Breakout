#pragma once
#include "IRenderer.h"
class Game
{
public:
	virtual ~Game(void) {};

	virtual void start() {};
	virtual void resetGame() {};
};

