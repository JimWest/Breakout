#pragma once
class Color
{

private:
	float r;
	float g;
	float b;
  
public:	      
    void setRGB(float r, float g, float b);

    void setR(float r);
    float getR();

    void setG(float g);
    float getG();

    void setB(float b);
    float getB();
    
	Color(void);
    Color(float r, float g, float b);

};

