//
// Created by Christian Reiswich on 3/31/25.
//

#include "../90_aux_src/helpers/println.hpp"
#include "DataVars.h"

void A1::printInfoFor(std::string town, unsigned int population, bool hasUniversity) {
    std::string pop = std::to_string(population);
    std::string hasUni = hasUniversity ? "hat eine Uni" : "hat keine Uni";
    std::string output = "Die Stadt " + town + " hat " + pop + " Einwohner und " + hasUni;
    println(output);
}

bool A6::isOfCharacterKind(char c, bool isAlphabetic, bool isNumeric, bool isUpperCase) {
    bool isA = isalpha(c);
    bool isN = isdigit(c);
    bool isU = isupper(c);

    return (isA == isAlphabetic && isN == isNumeric && isU == isUpperCase);
}

std::string A7::characterSequence(bool alphaLowerCase, bool alphaUpperCase, bool numeric) {
    std::string charSnake;
    std::string lowe;
    std::string up;
    std::string num;

    for(char c=32; c<127; c++) {
        lowe = islower(c) == alphaLowerCase ? charSnake += c : "";
        up = isupper(c) == alphaUpperCase ? charSnake += c : "";
        num = isdigit(c) == numeric ? charSnake += c : "";
    }
    println(charSnake);
}

int main() {

    A1::printInfoFor("Emden", 70000, true);
    A6::isOfCharacterKind('X', true, false, true);

    for(char c=32; c<127; c++) {

    }

    A7::characterSequence(true, false, true);
}