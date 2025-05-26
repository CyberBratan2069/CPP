#include <iostream>
#include <cmath>
#include <vector>
#include "../90_aux_src/helpers/AnsiConsole.h"


class Shape {
protected:
    Colors _colors;
public:
    Shape(Colors colors) : _colors(colors) {}
    virtual ~Shape() {}
    virtual void draw() = 0;
};

class Scene {
private:
    std::vector<Shape*> _shapes;
public:
    Scene() = default;
    ~Scene();
    void addShape(Shape* s);
    void drawAll();
};

class Point : public Shape {
private:
    int _x;
    int _y;
public:
    Point(int x, int y, Colors colors);
    void draw() override;
};

class Circle : public Shape {
private:
    int _x;
    int _y;
    int _radius;
public:
    Circle(int x, int y, int radius, Colors colors);
    void draw() override;
};

class Rectangle : public Shape {
protected:
    int _x;
    int _y;
    int _width;
    int _height;
public:
    Rectangle(int x, int y, int width, int height, Colors colors);
    void draw() override;
};

class PrintText : public Rectangle {
    std::string _text;
public:
    PrintText(int x, int y, int width, int height, std::string text, Colors colors);
    void draw() override;
};

class Triangle : public Shape {
private:
    int _x;
    int _y;
    int _length;
public:
    Triangle(int x, int y, int length, Colors colors);
    void draw() override;
};
