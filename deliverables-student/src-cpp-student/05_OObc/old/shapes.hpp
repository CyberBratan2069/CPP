#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"


struct Position{
  int x;
  int y;
  Position(): x(0), y(0) { }
  Position(int x_, int y_): x(x_), y(y_) { }
};

class Point{
protected:
  Position _position;
public:
  Point(int x, int y);
  void draw();
};


class Circle{
protected:
  Position  _position;
  int       _radius;
public:
  Circle(int x, int y, int radius);
  void draw();
};

class CrossHair : public Circle { 
public:
  CrossHair(int x, int y, int radius);
  void draw();
}; 

