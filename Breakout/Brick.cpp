#include "StdAfx.h"
#include "Brick.h"


Brick::Brick(void)
{
}


Brick::~Brick(void)
{
}

Brick::Brick(Vector2 origin, float width, float height, Color c, int life) : StaticBox(origin, width, height, c) {
    this->life = life;
}

void Brick::setLife(int life) {
    this->life = life;
}

int Brick::getLife() {
    return this->life;
}

void Brick::decLife() {
	this->life--;
}
