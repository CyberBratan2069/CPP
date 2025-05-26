//
// Created by Christian Reiswich on 3/31/25.
//

#include <string>

#ifndef CPP_DATAVARS_H
#define CPP_DATAVARS_H


class A1 {
public:
   static void printInfoFor(std::string town, unsigned int population, bool hasUniversity);
};

class A6 {
public:
    static bool isOfCharacterKind(char c, bool isAlphabetic, bool isNumeric, bool isUpperCase);
};

class A7 {
public:
    static std::string characterSequence(bool alphaLowerCase, bool alphaUpperCase, bool numeric);
};

#endif //CPP_DATAVARS_H
