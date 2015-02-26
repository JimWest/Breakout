#pragma once

// Describes and manipulates a vector in two-dimensional (2-D) space.
class Vector2
{

public:
	// X coordinate of the vector. 
	float x;

	// Y coordinate of the vector. 
	float y;

	// Default constructor, sets x and y to 0.
	Vector2(void);

	// Construct the vector from its coordinates. 
	//
	// @param x The x coordinate of the vector
	// @param y The y coordinate of the vector
	Vector2(float x, float y);

	// Overload of binary operator +
    Vector2 &operator+(Vector2);

	// Overload of binary operator -
	Vector2 &operator-(Vector2);

	// Overload of binary operator *
	Vector2 &operator*(float);

	// Overload of binary operator /
	Vector2 &operator/(float);

};

