//
// Created by Christian Reiswich on 4/2/25.
//

#include <iostream>
#ifndef CPP_VEKTOR2D_H
#define CPP_VEKTOR2D_H


class Vektor2D {
private:
    double x,y;

public:
    // Constructor
    Vektor2D(double x = 0, double y = 0);

    //Operator Overloading
    Vektor2D operator+(const Vektor2D& v) const;
    Vektor2D operator-(const Vektor2D& v) const;
    Vektor2D operator*(double skalar) const;
    bool operator==(const Vektor2D& v) const;

    // Ausgabeoperator überladen
    friend std::ostream& operator<<(std::ostream& os, const Vektor2D& v);

    // Getter-Methoden (optional)
    double getX() const;
    double getY() const;
};


#endif //CPP_VEKTOR2D_H
