#include <iostream>
#include <cmath>
#include <vector>
#include "../90_aux_src/helpers/AnsiConsole.h"
#include "shapes.hpp"

/** Alle Shapes löschen */
Scene::~Scene() {
    for (Shape* s : _shapes) {
        delete s;
    }
}

/** Shapes hinzufügen */
void Scene::addShape(Shape* s) {
    _shapes.push_back(s);
}

/** Shapes zeichnen */
void Scene::drawAll() {
    for (Shape* s : _shapes) {
        s->draw();
    }
}

/**********************************************************************************************************************/
/** Formen ************************************************************************************************************/
/**********************************************************************************************************************/
Point::Point(int x, int y, Colors colors)
    : Shape(colors), _x(x), _y(y) {}

void Point::draw(){
  ansiConsole.printText(_x, _y,"*", _colors);
}


Circle::Circle(int x, int y, int radius, Colors colors)
    : Shape(colors), _x(x), _y(y), _radius(radius) {}

void Circle::draw() {
    for (int i =-_radius; i<= _radius; i++) {
        int h = static_cast<int>(std::sqrt(_radius*_radius - i*i));
        ansiConsole.printText(_x + i, _y + h, "#", _colors);
        ansiConsole.printText(_x + i, _y - h, "#", _colors);
    }
    //ansiConsole.printText(_x, _y, "*", _colors); //Mitte
}


Rectangle::Rectangle(int x, int y, int width, int height, Colors colors)
    : Shape(colors), _x(x), _y(y), _width(width), _height(height) {}

void Rectangle::draw() {
    for(int i=-_width; i<= _width; i++) {
        ansiConsole.printText(_x + i, _y + _height, "-", _colors);
        ansiConsole.printText(_x + i, _y - _height, "-", _colors);
    }
    for(int i=-_height; i<= _height; i++) {
        ansiConsole.printText(_x + _width, _y + i, "|", _colors);
        ansiConsole.printText(_x - _width, _y + i, "|", _colors);
    }

    ansiConsole.printText(_x - _width, _y + _height, "+", _colors);
    ansiConsole.printText(_x + _width, _y + _height, "+", _colors);
    ansiConsole.printText(_x + _width, _y - _height, "+", _colors);
    ansiConsole.printText(_x - _width, _y - _height, "+", _colors);

    //ansiConsole.printText(_x, _y, "*", _colors); //Mitte
}

PrintText::PrintText(int x, int y, int width, int height, std::string text, Colors colors)
    : Rectangle(x, y, width, height, colors), _text(text) {}

void PrintText::draw() {
    ansiConsole.printText(_x, _y, _text, _colors);
    Rectangle::draw();
}

Triangle::Triangle(int x, int y, int length, Colors colors)
    : Shape(colors), _x(x), _y(y), _length(length) {}

void Triangle::draw() {
    for(int i=0; i<= _length; i++) {
        ansiConsole.printText(_x - i, _y + i, "*", _colors);
        ansiConsole.printText(_x + i, _y + i, "*", _colors);
    }
    for(int i=-_length; i<= _length; i++) {
        ansiConsole.printText(_x + i, _y + _length, "*", _colors);
    }
}

