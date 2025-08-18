/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created 8 Mar. 2025
 **********************************************************************************************************************/

#include "../90_aux_src/helpers/println.hpp"

//Compiling with => g++ -std=c++11 main_simple.cpp -o main_smpl


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

    println("01a_SMPL: ");

    println("\nPolynom1: ");
    for(int i=0; i<=10; i++) {
        println(i, ": ", polynom1(i));
    }

    println("\nPolynom2: ");
    for(int i=0; i<=10; i++) {
        println(i, ": ", polynom2(i));
    }

    println("\nPolynomAll: ");
    int i=0;
    while (i<=10) {
        println(i, ": ", polynomAll(i));
        i++;
    }

    return 0;
}

