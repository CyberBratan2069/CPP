#include <iostream>
#include <cmath>
#include <vector>
#include "../90_aux_src/helpers/AnsiConsole.h"
#include "shapes.hpp"


int main(/*int argc, char **argv*/) {
    ansiConsole.clearScreen();


    /** Scene Zeichnen */
    Scene scene;
    scene.addShape(new Point(10, 5, Colors::GREEN));
    scene.addShape(new Circle(30, 10, 8, Colors::BLUE));
    scene.addShape(new Rectangle(50, 15, 16, 6, Colors::CYAN_BRIGHT));
    scene.addShape(new PrintText(50, 15, 16, 6, "Text", Colors::CYAN_BRIGHT));
    scene.drawAll();

    /*
    Scene schneemann;
    schneemann.addShape(new Circle(40,8,4, Colors::WHITE));
    schneemann.addShape(new Circle(40,18,8, Colors::WHITE));

    for(int i=0; i< 30; i++) {
        int x = std::rand() % 80;
        int y = (std::rand() % 15) + 2;
        schneemann.addShape(new Point(x, y, Colors::WHITE));
    }
    schneemann.addShape(new Rectangle(60, 20, 7, 4, Colors::RED));
    schneemann.drawAll();
    */

    /** Trianlge */
    /*
    Triangle* triangle = new Triangle(20, 20, 5, Colors::BLUE);
    Scene tri;
    tri.addShape(triangle);
    tri.drawAll();
    */

    /** Rectangle */
    /*
    Scene rectangle;
    Rectanlge* rect = new Rectanlge(20, 10, 10, 6, Colors::RED);
    rectangle.addShape(rect);
    rectangle.drawAll();
    */

    /*
    // x=1 and y=1 is the upper left corner
    // x and y are more like column and row
    ansiConsole.printText(5,5,"Hello, World!");

    Circle* c = new Circle(30, 15, 10, Colors::GREEN);
    c->draw();

    std::vector<Point *> manyPoints;
    Point* p = new Point(10,10, Colors::RED);
    manyPoints.push_back(p);
  
    Point* p2 = new Point(2,10, Colors::RED);
    manyPoints.push_back(p2);

    manyPoints.push_back(new Point(30,15, Colors::RED));

    // let's draw the points!
    for (size_t i=0; i<manyPoints.size();i++){
    manyPoints[i]->draw();
    }
  
    CrossHair* target = new CrossHair(50, 15, 20, Colors::GREEN);
    target->draw();
  
    // delete unused objects
    for (size_t i=0; i<manyPoints.size();i++){
    delete manyPoints[i];
     }

    // Zeichnen
    Rectanlge* rectanlge = new Rectanlge(10, 15, 20, 20, Colors::BLUE);
    rectanlge->draw();

    // Speicher freigeben
    delete target;
    delete c;
    */

  return 0;
}
