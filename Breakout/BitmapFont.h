#pragma once
class BitmapFont
{
#include <GLFW/glfw3.h>
#include <string.h>

public:
    BitmapFont(
        CDC* dc, 
        char* fontname);
    virtual ~BitmapFont();
	
    void 
    DrawStringAt(
        GLfloat x, 
        GLfloat y, 
        GLfloat z, 
        char* s);

private:
    GLuint m_listbase;
    CDC* m_pDC;

private:
    // Hide these.
    BitmapFont() { }
    BitmapFont(const BitmapFont& obj) { }
    BitmapFont& operator=(const BitmapFont& obj) { return *this; }
};

