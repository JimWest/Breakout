#include "StdAfx.h"
#include "Color.h"

float Color::getR() const {
	return this->r;
}

void Color::setR(float r) {
	this->r = r;
}

float Color::getG() const {
	return this->g;
}

void Color::setG(float g) {
	this->g = g;
}

float Color::getB() const {
	return this->b;
}

void Color::setB(float b) {
	this->b = b;
}

void Color::setRGB(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::Color()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

Color::Color(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}





