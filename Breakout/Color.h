#pragma once

// Describes and manipulates a Color in the RGB color space.
// http://en.wikipedia.org/wiki/RGB_color_space
class Color
{

private:
	float r;
	float g;
	float b;

public:	  	
	// Returns the value of the red property.
	//
	// @return The current red value.	
	float getR() const;
	
	// Sets the value of the red property.
	//
	// @param r The new red value.	
	void setR(float r);

	// Returns the value of the green property.
	// 
	// @return The current green value.	
	float getG() const;

	// Sets the value of the green property.
	//
	// @param g The new green value.	
	void setG(float g);

	// Returns the value of the blue property.
	// 
	// @return The current blue value.	
	float getB() const;

	// Sets the value of the blue property.
	//
	// @param b The new blue value.	
	void setB(float b);

	// Sets the value of the red, green and blue property.
	//
	// @param r The new red value.
	// @param g The new greeb value.
	// @param b The new blue value.	
	void setRGB(float r, float g, float b);

	Color();
	Color(float r, float g, float b);

};

