// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../90_aux_src/helpers/println.hpp"
#include "pascalString.h"


// TODO symbols/characters '0' ... '9' ... 'a' ... 'f' to numbers 0 ... 15
int hexDigitToInt(char hexDigit) {
    //int numbers = digittoint(hexDigit);
    int number;

    if(hexDigit >= '0' && hexDigit <= '9') {
        number = hexDigit - '0';
    }
    if(hexDigit >= 'a' && hexDigit <= 'f') {
        number = hexDigit - 'a' + 10;
    }
    return number;
}


// TODO numbers 0 ... 15 to symbols/characters '0' ... '9' ... 'a' ... 'f'
char intToHexDigit(int number){
    return (char) number;
}

// TODO HexString reserve
PascalString reversed(PascalString pascalString) {
    PascalString output{};

    for(int i=pascalString.length -1; i>= 0; i--) {
        output.characters[i] = pascalString.characters[i];
    }
    return output;
}

// see https://www.arndt-bruenner.de/mathe/scripts/Zahlensysteme.htm
int hexStringToInt(PascalString hexStr){

}


PascalString intToHexString(int n){
  PascalString result = {0, {0,}};
  // TODO
  return result;
}


/**
ISBN-10 test cases: Bjarne Stroustrup: 3446439617, 0321992784, 3747506259
 The Art Of Computer Programming Volume 3; Knuth, Donald E. 020103803X
 see https://de.wikipedia.org/wiki/Internationale_Standardbuchnummer#ISBN-10
*/

// checks if the last char of a string conforms to the ISBN-10 checksum formula
bool Isbn10IsValid(PascalString isbn){
    int calculatedChecksum = 0;
    char lastChar = isbn.characters[isbn.length-1];
    int givenChecksum;
    if ((lastChar == 'x') || (lastChar == 'X')) {
        givenChecksum = 10;
    }else{
        givenChecksum = hexDigitToInt(lastChar);
    }
    //
    // TODO: implement calculation of calculatedChecksum
    //
    return calculatedChecksum == givenChecksum;
}


int main(/*int argc, char** argv, char** envp*/){

    hexDigitToInt('c');
    intToHexDigit(13);

    println(fromString("Hello, World!"));
    PascalString s1 = fromString("100");      // s1 = {3, {'1', '0', '0',}};
    PascalString s2 = fromString("fffe");     // s2 = {4, {'f', 'f', 'f', 'e',}};
    println("s1 = 0x", s1, " = ", hexStringToInt(s1));
    println("s2 = 0x", s2, " = ", hexStringToInt(s2));

    reversed(s1);
    reversed(s2);
    return 0;
}

