//
// Created by Christian Reiswich on 4/2/25.
//
#include "Vektor2D.h"

int main() {
    Vektor2D v1(3, 4), v2(1, 2);

    Vektor2D summe = v1 + v2;      // Addition
    Vektor2D differenz = v1 - v2;  // Subtraktion
    Vektor2D skalarProdukt = v1 * 2.5; // Skalarmultiplikation

    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "Summe: " << summe << "\n";
    std::cout << "Differenz: " << differenz << "\n";
    std::cout << "Skalarprodukt: " << skalarProdukt << "\n";

    if (v1 == v2)
        std::cout << "v1 und v2 sind gleich.\n";
    else
        std::cout << "v1 und v2 sind ungleich.\n";

    return 0;
}