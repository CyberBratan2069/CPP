//
// Created by Christian Reiswich on 2/3/25.
//

#include "multipleDefinitions.h"

/*
 * eine Funktion oder Variable wurde mehrmals definiert;
 */

int polynom(int x) {
    return (x - 1) * (x - 2) * (x - 3);
}

int polynom(int x) {
    return (x - 1) * (x - 2) * (x - 3);
}

int main() {
    polynom(1);
    return 0;
}