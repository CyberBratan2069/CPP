#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.hpp"
#include "shapes.hpp"


int main(/*int argc, char **argv*/)
{
  ansiConsole.clearScreen();
  // x=1 and y=1 is the upper left corner
  // x and y are more like column and row
  ansiConsole.printText(5,5,"Hello, World!");

  Circle* c = new Circle(30, 15, 10);
  c->draw();

  std::vector<Point *> manyPoints;
  Point* p = new Point(10,10);
  manyPoints.push_back(p);
  
  Point* p2 = new Point(2,10);
  manyPoints.push_back(p2);

  manyPoints.push_back(new Point(30,15));

  // let's draw the points!
  for (size_t i=0; i<manyPoints.size();i++){
    manyPoints[i]->draw();
  }
  
  CrossHair* target = new CrossHair(50, 15, 20);
  target->draw();
  
  // delete unused objects
  for (size_t i=0; i<manyPoints.size();i++){
    delete manyPoints[i];
  }
  
  delete target;
  delete c;

  return 0;
}
