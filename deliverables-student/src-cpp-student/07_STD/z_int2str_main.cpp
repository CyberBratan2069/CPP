#include "println.hpp"
#include "z_int2str_helpers.hpp"
#include <cassert>



std::string numberToAsciiString(unsigned long value, unsigned long base){
  std::string result = "";
  do {
    unsigned long lastDigit  = value % base;            // last digit`s int value
    char c = numberToAsciiDigit(lastDigit); // last digit`s character
    value =  value / base;                    // all remaining digits, i.e. shift right
    result += c;
  } while (value);
  std::reverse(result.begin(), result.end());
  return result;
}

unsigned long asciiStringToNumber(std::string string_value, unsigned long base){
  unsigned long result = 0;
  for(size_t i=0; i<string_value.length();i++){
    result *= base;
    result += digitToNumber(string_value[i]);
  }
  return result;
}

#ifdef TEMPLATED

template<unsigned long BASE>
unsigned long asciiStringToNumber_T(std::string string_value){
  unsigned long result = 0;
  for(size_t i=0; i<string_value.length();i++){
    result *= BASE;
    result += digitToNumber(string_value[i]);
  }
  return result;
}

template<unsigned long BASE>
std::string numberToAsciiString_T(unsigned long value){
  std::string result = "";
  do {
    unsigned long lastDigit  = value % BASE;            // last digit`s int value
    char c = numberToAsciiDigit(lastDigit); // last digit`s character
    value =  value / BASE;                    // all remaining digits, i.e. shift right
    result += c;
  } while (value);
  std::reverse(result.begin(), result.end());
  return result;
}

/**
typedef std::string (*fptr1)( unsigned long );
constexpr fptr1 n2a_T = numberToAsciiString_T<16>;

typedef unsigned long (*fptr2) (std::string );
constexpr fptr2 a2n_T = asciiStringToNumber_T<16>;
*/

///using n2a = std::string (*)numberToAsciiString_T<16>() ;

#endif   

void test1(unsigned long iterations){
  assert(numberToHexString(0x0) == "0");
  assert(numberToHexString(0x1) == "1");
  assert(numberToHexString(0x9) == "9");
  assert(numberToHexString(0xA) == "A");
  assert(numberToHexString(0xFE) == "FE");
  assert(numberToHexString(0xFF1789E) == "FF1789E");
  for (unsigned long i=0; i<iterations;i++){
#ifdef TEMPLATED
///    println("<> ", numberToAsciiString_T<16>(i));
///    if(a2n_T(n2a_T(i)) != i){
    if(asciiStringToNumber_T<16>(numberToAsciiString_T<16>(i)) != i){
      println("error at i=",i);
      exit(1);
    }
#else
///    println("() ", numberToHexString(i));
    if(hexStringToNumber(numberToHexString(i)) != i){
      println("error at i=",i);
      exit(1);
    }
#endif
  }
}


int main(int argc, char* argv[]){
  unsigned long iterations = 16;
  if (argc==2){
    iterations = std::stoul(argv[1]);
    test1(iterations);
  }else{
    println("usage: a.out <iterations>");  
  }
  return 0;
}
