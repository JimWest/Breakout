#include "StdAfx.h"
#include "Brick.h"

int Brick::getLife() {
    return this->life;
}

void Brick::setLife(int life) {
    this->life = life;
}


Brick::Brick(void)
{
}

Brick::Brick(Vector2 origin, float width, float height, Color c, int life) : StaticBox(origin, width, height, c) {
    this->life = life;
}

Brick::~Brick(void)
{
}


void Brick::decLife() {
	this->life--;
}

