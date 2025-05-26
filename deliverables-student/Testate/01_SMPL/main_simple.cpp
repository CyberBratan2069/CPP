//
// Created by Christian Reiswich on 3/8/25.
//

#include "../90_aux_src/helpers/println.hpp"

//Compiling with => g++ -std=c++11 myfile.cpp -o myprogram
//Compiling with => clang++ -std=c++11 main.cpp example.cpp -o example


int polynom1(int x) {
    return (x-1) * (x-2) * (x-3);
}

int polynom2(int x) {
    return (x-4) * (x-5) * (x-6);
}

int polynomAll(int x) {
    return polynom1(x) * polynom2(x);
}

int main() { // program entry point

    println("Polynom1: ");
    for(int i=0; i<=10; i++) {
        println(i, ": ", polynom1(i));
    }

    println("Polynom2: ");
    for(int i=0; i<=10; i++) {
        println(i, ": ", polynom2(i));
    }

    println("PolynomAll: ");
    int i=0;
    while (i<=10) {
        println(i, ": ", polynomAll(i));
        i++;
    }

    return 0;
}

