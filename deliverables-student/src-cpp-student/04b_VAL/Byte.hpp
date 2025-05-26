#ifndef BYTE_HPP
#define BYTE_HPP

#include <cstdint>
#include <cstddef>
#include <string>

/*
 Type Byte "behaves like int", because it is a regular type (AKA value type)
  
 The regular concept specifies that a type is regular, that is, it is copyable, default constructible, and equality comparable. It is satisfied by types that behave similarly to built-in types like int, and that are comparable with ==.

 https://en.cppreference.com/w/cpp/concepts/regular 
*/

struct Byte {
  uint8_t bits;



  Byte();                       // default ctor  
  Byte(uint8_t);                // for initialization 'Byte b(0xff)'

#ifdef TRACE
  Byte(const Byte& src);        // for initialization 'Byte newer = older;'
  Byte& operator=(const Byte& src);   // assignment; overwrites old value  
#else
  Byte(const Byte& src)            = default ; // let the compiler generate it
  Byte& operator=(const Byte& src) = default ; // let the compiler generate it
  // C++20: let the compiler generate all comparison operators
  // friend auto operator<=>(const P&, const P&) = default; 
#endif
  
};

bool operator==(const Byte& left, const Byte& right);
bool operator!=(const Byte& left, const Byte& right);
bool operator< (const Byte& left, const Byte& right);
std::string as_string(const Byte& b);



/**
  Byte& shl(int steps);
  Byte& shr(int steps);
  explicit operator uint8_t();
  bool operator[](std::size_t idx);
*/
#endif  ///  BYTE_HPP
