//
// Created by Christian Reiswich on 2/3/25.
//

//#include "undeclaredIdentifier.h" //Undeclard Indentifier
#include "../../../../90_aux_src/helpers/println.hpp"

/*
 * Das Programm ruft in main nun eine Funtion auf die vorher garnicht deklariert wurde. Er weiß garnicht, dass sie
 * existiert.
 * Er erkennt die Funktion oder Variable nicht.
 */

int main() {
    println(polynom(1));
}

int polynom(int x) {
    return (x-1) * (x-2) * (x-3);
}