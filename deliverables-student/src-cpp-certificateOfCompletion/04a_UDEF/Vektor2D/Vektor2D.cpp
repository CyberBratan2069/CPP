//
// Created by Christian Reiswich on 4/2/25.
//

#include "Vektor2D.h"


// Konstruktor
Vektor2D::Vektor2D(double x, double y) : x(x), y(y) {}

// Operatorüberladungen
Vektor2D Vektor2D::operator+(const Vektor2D& v) const {
    return Vektor2D(x + v.x, y + v.y);
}

Vektor2D Vektor2D::operator-(const Vektor2D& v) const {
    return Vektor2D(x - v.x, y - v.y);
}

Vektor2D Vektor2D::operator*(double skalar) const {
    return Vektor2D(x * skalar, y * skalar);
}

bool Vektor2D::operator==(const Vektor2D& v) const {
    return (x == v.x && y == v.y);
}

// Überladung des << Operators für die Ausgabe
std::ostream& operator<<(std::ostream& os, const Vektor2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// Getter-Methoden (optional)
double Vektor2D::getX() const {
    return x;
}

double Vektor2D::getY() const {
    return y;
}