#include "z_int2str_helpers.hpp"

char numberToAsciiDigit(unsigned long n){
  char result = '?';
  if ((n>=0)&&(n<=9)){
    result = '0' + n;
  } else if ((n>=10)&&(n<=36)){
    result = 'A' + n - 10;
  }
  ///assert(result!='?'); // FIXME: didn't want to repeat the conditions up front
  return result;
}

int digitToNumber(char ASCIIencodedDigit){
  int result=-1;
  if ((ASCIIencodedDigit>='0')&&(ASCIIencodedDigit<='9')){
    result = ASCIIencodedDigit - '0';
  } else if ((ASCIIencodedDigit>='A')&&(ASCIIencodedDigit<='Z')){
    result =  ASCIIencodedDigit - 'A' + 10;
  } else if ((ASCIIencodedDigit>='a')&&(ASCIIencodedDigit<='z')){
    result =  ASCIIencodedDigit - 'a' + 10;
  }
  ///assert(result>=0); // FIXME: didn't want to repeat the conditions up front
  return result;
}

std::string numberToHexString(unsigned long value){
  return numberToAsciiString(value, 16);
}

unsigned long hexStringToNumber(std::string hex_str){
  return asciiStringToNumber(hex_str,16);
}


