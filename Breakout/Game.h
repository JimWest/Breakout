#pragma once
#include "IRenderer.h"

// An abstract class for Games.
class Game
{
public:
	virtual ~Game(void) {};

	virtual void start() {};
	virtual void resetGame() {};
};

