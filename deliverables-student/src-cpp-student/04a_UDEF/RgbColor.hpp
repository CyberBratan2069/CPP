// file: FixedPoint.hpp
#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP

#include <string>

struct RgbColor {
  unsigned int m_red;
  unsigned int m_green;
  unsigned int m_blue;

public:
  
  RgbColor();
  RgbColor(RgbColor& src) : m_red(src.m_red), m_green(src.m_green), m_blue(src.m_blue)  {}
  explicit RgbColor(uint32_t rgbVal);

  
  
  uint8_t red()   const ;
  uint8_t green() const ;
  uint8_t blue()  const ;


  // todo: implement methods an operators
  
  explicit operator bool ();
  
  
};


std::string as_string(RgbColor);  // for println()

#endif

