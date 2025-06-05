// file: main_02_MENT.cpp
// THIS IS C++, use clang++

#include "../90_aux_src/helpers/println.hpp"
#include "pascalString.h"

/**
 * char '0' ... '9' ... 'a' ... 'f to number 0 ... 15
 */
int hexDigitToInt(char hexDigit) {
    int number;

    if(hexDigit >= '0' && hexDigit <= '9') {
        number = hexDigit - '0';
    }
    if(hexDigit >= 'a' && hexDigit <= 'f') {
        number = hexDigit - 'a' + 10;
    }
    return number;
}

/**
 * number 0 ... 15 to char '0' ... '9' ... 'a' ... 'f'
 */
char intToHexDigit(int number) {
    char character;

    if(number >= 0 && number <= 9) {
        character = number + '0';
    }
    if(number >= 10 && number <= 15) {
        character = number + 'a' - 10;
    }
    return character;
}

/**
 * Gibt String Rückwärts zurück
 */
PascalString reversed(PascalString pascalString) {
    PascalString output{};               //Output
    int psLength = pascalString.length;  //Länge von pascalString

    output.length = psLength;            //Output in gleiche Länge setzten wie output

    for(int i=0; i < psLength; i++) {    //pascalString Rückwärts in output reinschreiben
        output.characters[i] += pascalString.characters[psLength - 1 - i];
    }
    return output;
}

/**
 * (100)₁₆ = (1 × 16²) + (0 × 16¹) + (0 × 16⁰) = (256)₁₀
 */
// see https://www.arndt-bruenner.de/mathe/scripts/Zahlensysteme.htm
int hexStringToInt(PascalString hexStr) {
    int output = 0;
    int base   = 1;

    for(int i=hexStr.length -1; i>=0; i--){
        int value = digittoint(hexStr.characters[i]);
        output += value + base;
        base *= 16;
    }
    return output;
}

/**
 * Convertiert einen Int wert in einen Hex PascalString um
 * 100 = 100/16 = 6,25  => 0,25  * 16 = 4
 *     = 6/16   = 0,375 => 0,375 * 16 = 6
 */
PascalString intToHexString(int decimal){
    PascalString hex = {};
    std::ostringstream oss;
    oss << std::hex << decimal;
    int hexLength = oss.str().length();

    hex.length = hexLength;

    for(int i=0; i<hexLength; i++) {
        hex.characters[i] += oss.str()[i];
    }

    return hex;
}


PascalString intToDualString(uint8_t decimal) {
    PascalString binary = {};
    int bitsLength = sizeof(decimal) * 8;

    binary.length = bitsLength;

    for(int i=0; i<bitsLength; i++) {
        binary.characters[i] += ((decimal & (0x80 >> i)) == 0) ? '0' : '1'; //0x80 = 1000 0000
    }
    binary.characters[bitsLength] = '\0';

    return binary;
}

/**
ISBN-10 test cases: Bjarne Stroustrup: 3446439617, 0321992784, 3747506259
 The Art Of Computer Programming Volume 3; Knuth, Donald E. 020103803X
 see https://de.wikipedia.org/wiki/Internationale_Standardbuchnummer#ISBN-10
*/

// checks if the last char of a string conforms to the ISBN-10 checksum formula
bool Isbn10IsValid(PascalString isbn) {
    int calculatedChecksum;
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
    int sum = 0;
    for (int i = 0; i < isbn.length - 1; i++) {
        int ziffer = hexDigitToInt(isbn.characters[i]);
        sum += ziffer * (10 - i);
    }
    int remainder = sum % 11;
    calculatedChecksum = (11 - remainder) % 11;

    return calculatedChecksum == givenChecksum;
}


int main(/*int argc, char** argv, char** envp*/){
    println(fromString("Hello, World!"));
    PascalString s1 = fromString("100");      // s1 = {3, {'1', '0', '0',}};
    PascalString s2 = fromString("fffe");     // s2 = {4, {'f', 'f', 'f', 'e',}};
    println("s1 = 0x", s1, " = ", hexStringToInt(s1));
    println("s2 = 0x", s2, " = ", hexStringToInt(s2));

    println("\033[01;34m============== Grundgerüst ==============\033[0m");
    println("hexDigitToInt");
    for(char c= '0'; c<= '9'; c++) {
        println(c, " -> ", hexDigitToInt(c));
    }
    for(char c= 'a'; c<= 'f'; c++) {
        println(c, " -> ", hexDigitToInt(c));
    }

    println("\nhexDigitToInt");
    for(int i=0; i<= 15; i++) {
        println(i, " -> ", intToHexDigit(i));
    }

    println("s1 = 0x",  s1, " = s1 reserved = 0x", reversed(s1));
    println("s2 = 0x",  s2, " = s2 reserved = 0x", reversed(s2));

    println("\033[01;34m============== Modifikation ==============\033[0m");
    println("hexStringToInt: ",s1, " -> ", hexStringToInt(s1));
    println("intToHexString: ", 100, " -> ", intToHexString(100));
    println("intToDualString: ", 5 , " -> ", intToDualString(5));

    PascalString isbn1 = fromString("3446439617");
    PascalString isbn2 = fromString("0321992784");
    PascalString isbn3 = fromString("3747506259");
    PascalString isbn4 = fromString("020103803X");

    PascalString isbn5 = fromString("1116439617");
    PascalString isbn6 = fromString("2221992784");
    PascalString isbn7 = fromString("3337506259");
    PascalString isbn8 = fromString("444103803X");

    println(isbn1, " is Valid ?: ", Isbn10IsValid(isbn1));
    println(isbn2, " is Valid ?: ", Isbn10IsValid(isbn2));
    println(isbn3, " is Valid ?: ", Isbn10IsValid(isbn3));
    println(isbn4, " is Valid ?: ", Isbn10IsValid(isbn4));

    println(isbn5, " is Valid ?: ", Isbn10IsValid(isbn5));
    println(isbn6, " is Valid ?: ", Isbn10IsValid(isbn6));
    println(isbn7, " is Valid ?: ", Isbn10IsValid(isbn7));
    println(isbn8, " is Valid ?: ", Isbn10IsValid(isbn8));

    return 0;
}