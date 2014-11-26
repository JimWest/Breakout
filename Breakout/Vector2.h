#pragma once
class Vector2
{

public:
	float x;
	float y;

	Vector2(void);
	Vector2(float x, float y);
	~Vector2(void);

    Vector2 &operator+(Vector2);
	Vector2 &operator-(Vector2);

	Vector2 &operator*(double);

};

