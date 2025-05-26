#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>

char numberToAsciiDigit(unsigned long n);

int digitToNumber(char ASCIIencodedDigit);

std::string numberToHexString(unsigned long value);

unsigned long hexStringToNumber(std::string hex_str);

std::string numberToAsciiString(unsigned long value, unsigned long base);

unsigned long asciiStringToNumber(std::string string_value, unsigned long base);

#endif
