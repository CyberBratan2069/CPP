#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.hpp"
#include "shapes.hpp"


Point::Point(int x, int y){
  _position = Position(x,y);
}


void Point::draw(){
  ansiConsole.printText(_position.x,_position.y,"*", Colors::RED);
}


Circle::Circle(int x, int y, int radius){
  _position = Position(x,y);
  _radius=radius;
}

void Circle::draw(){
  /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
   * Höhensatz des Euklid
   * */
  int x_start = _position.x - _radius/2;
  int x_stop  = _position.x + _radius/2;

  for(int i=x_start; i<=x_stop; i++){
    double x_relative = double(i) - double(x_start);
    double h = sqrt(x_relative*(x_stop-x_start-x_relative));
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y +h,"#",
                          Colors::GREEN);
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y -h,"#",
                          Colors::GREEN);

  }
}

CrossHair::CrossHair(int x, int y, int radius)
: Circle(x,y,radius)
{
}

void CrossHair::draw(){
  Circle::draw();
  int x_start = _position.x - _radius/2 + 2;
  int x_stop  = _position.x + _radius/2 - 2;
  for(int i=x_start; i<=x_stop; i+=2){
    ansiConsole.printText( i, _position.y , "-" , AnsiColor::RED);  
  }
  int y_start = _position.y - _radius/2 + 2;
  int y_stop  = _position.y + _radius/2 - 2;
  for(int j=y_start; j<=y_stop; j+=2){
    ansiConsole.printText( _position.x, j , "|" , AnsiColor::RED);  
  }
  ansiConsole.printText(_position.x,_position.y,"+", AnsiColor::RED);
}

