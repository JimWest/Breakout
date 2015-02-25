#include "StdAfx.h"
#include "Color.h"


float Color::getR() {
  return this->r;
}

void Color::setR(float r) {
    this->r = r;
}

float Color::getG() {
  return this->g;
}

void Color::setG(float g) {
    this->g = g;
}


float Color::getB() {
  return this->b;
}

void Color::setB(float b) {
    this->b = b;
}

Color::Color(void)
{
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Color::setRGB(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

  

