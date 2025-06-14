#include "../90_aux_src/helpers/println.hpp"
#include <cstdint>

uint32_t fromRGB(uint8_t red, uint8_t green, uint8_t blue){
  return (red << 16) | (green<<8) | (blue);
}

uint8_t red(uint32_t rgb){
  return (rgb & 0xFF0000) >> 16;
}

uint8_t green(uint32_t rgb){
  return (rgb & 0xFF00) >> 8;
}

uint8_t blue(uint32_t rgb){
  return (rgb & 0xFF);
}

int main(/*int argc, char** argv, char** envp*/){
  uint32_t pureRed = fromRGB(255,0,0);
  println("pure red is ", pureRed);
  println("pure blue is ", fromRGB(0,0,255));
  println("red part of pure red is ", red(pureRed) );
  return 0;
}

