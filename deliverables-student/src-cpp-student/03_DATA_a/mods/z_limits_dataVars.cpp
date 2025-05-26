//
// Created by Christian Reiswich on 3/15/25.
//

#include "../../90_aux_src/helpers/println.hpp"
#include <format>
#include <cctype>


void printInfoFor(std::string town, unsigned int population, bool hasUniversity) {
    std::string hu = hasUniversity ? "have a uni" : "dont have a uni";
    std::string pop = as_string(population);
    std::string text = "the Town" + town + " have a population of " + pop + " and " + hu;
    println(text);

    println("Pop as int: ", population);
    std::cout << "Pop as String: " << pop << std::endl;
}

int polynom1(int x) {
    return (x-1) * (x-2) * (x-3);
}

int polynom2(int x) {
    return (x-4) * (x-5) * (x-6);
}

int polynomAll(int x) {
    return polynom1(x) * polynom2(x);
}

int numZeros() {
    int count = 0;

    for(int i=0; i< 10; i++) {
        if(polynom1(i) == 0) count++;
    }

    return count;
}

int isOfCharacterKind(char c, bool isAlphabetic, bool isNumeric, bool isUpperCase) {
    if(isalpha(c)) println(c, " is Alphabetic: ", isAlphabetic);
    if(isdigit(c)) println(c, " is Numeric: ", isNumeric);
    if(isupper(c)) println(c, " is Upper Case: ", isUpperCase);
    return 0;
}

std::string characterSequence(bool alphaLowerCase, bool alphaUpperCase, bool numeric) {
    for(int i=0; i<65; i++) {

    }
}

int main() {

    printInfoFor("Emden", 70000, true);

    println("Polynom1: ");
    for(int i=0; i<10; i++) {
        println(polynom1(i));
    }

    println("polynom2: ");
    for(int i=0; i<10; i++) {
        println(polynom2(i));
    }

    println("PolynomAll: ");
    for(int i=0; i<10; i++) {
        println(polynomAll(i));
    }

    println("Nullstellen von Polynom1 sind: ", numZeros());

    isOfCharacterKind('X', true, false, true);

    characterSequence(true, false, true);

}