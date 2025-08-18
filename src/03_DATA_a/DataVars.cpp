/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created on 31 Mar. 2025
 * @last modified 10 Apr. 2025
 * @version 1.0
 * @brief
 **********************************************************************************************************************/


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
    std::string result;

    for(char c=32; c<127; c++) {
        if(alphaLowerCase && std::islower(c)) result += c;
        if(alphaUpperCase && std::isupper(c)) result += c;
        if(numeric        && std::isdigit(c)) result += c;
    }

    return result;
}

int main() {

    A1::printInfoFor("Emden", 70000, true);
    println(A6::isOfCharacterKind('X', true, false, true));
    println(A7::characterSequence(true, false, true));

}