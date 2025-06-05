
#ifndef ANSICOLSOLE_HPP
#define ANSICOLSOLE_HPP

#ifdef println_hpp
#error "do not use AnsiConsole and println simultaneously"
#endif


#include <iostream>

enum class Colors {
  NONE = 0,
  BLACK   = 30,
  RED     = 31,
  GREEN   = 32,
  YELLOW  = 33,
  BLUE    = 34,
  MAGENTA = 35,
  CYAN    = 36, 
  WHITE   = 37,
  BLACK_BRIGHT   = 30+60,
  RED_BRIGHT     = 31+60,
  GREEN_BRIGHT   = 32+60,
  YELLOW_BRIGHT  = 33+60,
  BLUE_BRIGHT    = 34+60,
  MAGENTA_BRIGHT = 35+60,
  CYAN_BRIGHT    = 36+60, 
  WHITE_BRIGHT   = 37+60
};

#define AnsiColor Colors

class AnsiConsole {
  // protected:
  // can only be used by members of AnsiConsole and its 
  // derived classes
  int maxY;
  bool hasBeenUsed;
protected:            
  void pushCursorPos();
  void popCursorPos();
  
public:
  AnsiConsole();
  ~AnsiConsole();
  void clearScreen();
  void hideCursor();
  void showCursor();
  void printText(int x, int y, std::string text);
  void printText(int x, int y, std::string text, Colors color, bool bold=false);
  int maxYpos();
  void resetMaxYpos();
};

extern AnsiConsole ansiConsole;

#endif //ANSICOLSOLE_HPP
