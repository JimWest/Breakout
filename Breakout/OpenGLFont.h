#pragma once

#include <iostream>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>

// Taken from http://content.gpwiki.org/OpenGL_Font_System

class OpenGLFont
{
public:
  OpenGLFont(const char* file);
  ~OpenGLFont();
 
  // The line height is constant
  size_t Line_Height() const;
  // Knowing the width of a character or a string can be useful if you
  // want your UI to look good at all.
  size_t Char_Width(unsigned char c) const;
  size_t String_Width(const std::string& str) const;
  // Draw a string at a given position.
  void Draw_String(const std::string& str, float x, float y);
 
private:
  // Information about a glyph. Tex_y2 can be calculated from tex_y1
  // and _tex_line_height (see below). Advance is the width of the
  // glyph in screen space.
  struct Glyph
  {
    float tex_x1, tex_y1, tex_x2;
    size_t advance;
  };
  // An array to store the glyphs.
  Glyph* _glyphs;
  // A table to quickly get the glyph belonging to a character.
  Glyph* _table[256];
  // The line height, in screen space and in texture space, and the
  // OpenGL id of the font texture.
  size_t _line_height, _texture;
  float _tex_line_height;
};

