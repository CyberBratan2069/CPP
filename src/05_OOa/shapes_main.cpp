/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created 13 Mai 2025
 **********************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include "../90_aux_src/helpers/AnsiConsole.h"
#include "shapes.hpp"


int main(/*int argc, char **argv*/) {
    ansiConsole.clearScreen();


    Scene scene;
    scene.addShape(new Point(10, 5, Colors::GREEN));
    scene.addShape(new Circle(30, 10, 8, Colors::BLUE));
    scene.addShape(new Rectangle(50, 15, 16, 6, Colors::CYAN_BRIGHT));
    scene.addShape(new Triangle(25, 10, 20, Colors::MAGENTA));
    scene.addShape(new PrintText(50, 15, 16, 6, "Text", Colors::CYAN_BRIGHT));
    scene.drawAll();


    /*
    Scene snowman;
    snowman.addShape(new Circle(40,8,4, Colors::WHITE));
    snowman.addShape(new Circle(40,18,8, Colors::WHITE));

    for(int i=0; i< 30; i++) {
        int x = std::rand() % 80;
        int y = (std::rand() % 15) + 2;
        snowman.addShape(new Point(x, y, Colors::WHITE));
    }
    snowman.addShape(new Rectangle(60, 20, 7, 4, Colors::RED));
    snowman.drawAll();
    */

  return 0;
}
