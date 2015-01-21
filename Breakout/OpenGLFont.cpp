#include "StdAfx.h"
#include "OpenGLFont.h"

// Helper function to read a piece of data from a stream.
template<class T, class S>
void Read_Object(T& to_read, S& in)
{
  in.read(reinterpret_cast<char*>(&to_read), sizeof(T));
}
 
// This is how glyphs are stored in the file.
struct Glyph_Buffer
{
  unsigned char ascii, width;
  unsigned short x, y;
};
 
OpenGLFont::OpenGLFont(const char* filename)
  : _line_height(0),
    _texture(0),
    _tex_line_height(0)
{
  // Open the file and check whether it is any good (a font file
  // starts with "F0")
  std::ifstream input(filename, std::ios::binary);
  if (input.fail() || input.get() != 'F' || input.get() != '0')
    throw std::runtime_error("Not a valid font file.");
 
  // Get the texture size, the number of glyphs and the line height.
  size_t width, height, n_chars;
  Read_Object(width, input);
  Read_Object(height, input);
  Read_Object(_line_height, input);
  Read_Object(n_chars, input);
  _tex_line_height = static_cast<float>(_line_height) / height;
 
  // Make the glyph table.
  _glyphs = new Glyph[n_chars];
  for (size_t i = 0; i != 256; ++i)
    _table[i] = NULL;
 
  // Read every glyph, store it in the glyph array and set the right
  // pointer in the table.
  Glyph_Buffer buffer;
  for (size_t i = 0; i < n_chars; ++i){
    Read_Object(buffer, input);
    _glyphs[i].tex_x1 = static_cast<float>(buffer.x) / width;
    _glyphs[i].tex_x2 = static_cast<float>(buffer.x + buffer.width) / width;
    _glyphs[i].tex_y1 = static_cast<float>(buffer.y) / height;
    _glyphs[i].advance = buffer.width;
 
    _table[buffer.ascii] = _glyphs + i;
  }
  // All chars that do not have their own glyph are set to point to
  // the default glyph.
  Glyph* default_glyph = _table[(unsigned char)'\xFF'];
  // We must have the default character (stored under '\xFF')
  if (default_glyph == NULL)
    throw std::runtime_error("Font file contains no default glyph");
  for (size_t i = 0; i != 256; ++i){
    if (_table[i] == NULL)
      _table[i] = default_glyph;
  }
 
  // Store the actual texture in an array.
  unsigned char* tex_data = new unsigned char[width * height];
  input.read(reinterpret_cast<char*>(tex_data), width * height);
 
  // Generate an alpha texture with it.
  glGenTextures(1, &_texture);
  glBindTexture(GL_TEXTURE_2D, _texture);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA8, width, height, 0, GL_ALPHA,
               GL_UNSIGNED_BYTE, tex_data);
  // And delete the texture memory block
  delete[] tex_data;
}


OpenGLFont::~OpenGLFont(void)
{
	// Release texture object and glyph array.
  glDeleteTextures(1, &_texture);
  delete[] _glyphs;
}

size_t OpenGLFont::Line_Height() const
{
  return _line_height;
}
size_t OpenGLFont::Char_Width(unsigned char c) const
{
  return _table[c]->advance;
}
 
size_t OpenGLFont::String_Width(const std::string& str) const
{
  size_t total = 0;
  for (size_t i = 0; i != str.size(); ++i)
    total += Char_Width(str[i]);
  return total;
}

void OpenGLFont::Draw_String(const std::string& str, float x, float y)
{
  glBindTexture(GL_TEXTURE_2D, _texture);
 
  // Simply draw quads textured with the current glyph for every
  // character, updating the x position as we go along.
  glBegin(GL_QUADS);
  for (size_t i = 0; i != str.size(); ++i){
    Glyph* glyph = _table[str[i]];
 
    glTexCoord2f(glyph->tex_x1, glyph->tex_y1);
    glVertex2f(x, y);
    glTexCoord2f(glyph->tex_x1, glyph->tex_y1 + _tex_line_height);
    glVertex2f(x, y + _line_height);
    glTexCoord2f(glyph->tex_x2, glyph->tex_y1 + _tex_line_height);
    glVertex2f(x + glyph->advance, y + _line_height);
    glTexCoord2f(glyph->tex_x2, glyph->tex_y1);
    glVertex2f(x + glyph->advance, y);
 
    x += glyph->advance;
  }
  glEnd();
}
