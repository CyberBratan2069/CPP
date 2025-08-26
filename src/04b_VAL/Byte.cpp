
#include "Byte.hpp"
#ifdef TRACE
#include "println.hpp"
#endif


Byte::Byte()                        // default ctor
{
#ifdef TRACE
println("Byte::Byte()");
#endif
  bits = 0;
}
  
Byte::Byte(uint8_t u)                  // for initialization 'Byte b(0xff)'
: bits(u)                              // member initiilizer
{
#ifdef TRACE
println("Byte::Byte(uint8_t u) u=", u);
#endif
}
  
  
#ifdef TRACE
Byte::Byte(const Byte& src)            // for initialization 'Byte newer = older;'
: bits(src.bits)                       // member initiilizer
{
println("Byte::Byte(const Byte& src.bits=", src.bits);
}
#endif
  


#ifdef TRACE
Byte& Byte::operator=(const Byte& src) // assignment; overwrites old value
{
  println("Byte& Byte::operator=(Byte& src) src.bits=", src.bits);
  bits = src.bits;
  return *this;
}
#endif

Byte& Byte::operator<<(int shifts) {
    bits <<= shifts;
    return *this;
}

Byte& Byte::operator>>(int shifts) {
    bits >>= shifts;
    return *this;
}

Byte& Byte::shl(int steps) {
    return Byte::operator<<(steps);
}

Byte& Byte::shr(int steps) {
    return Byte::operator>>(steps);
}

Byte& Byte::setBit(int pos) {
    bits |= (1u << pos);
    return *this;
}

Byte& Byte::getBit(int pos) {
    bits = (bits >> pos) & 1u;
    return *this;
}

Byte& Byte::clearBit(int pos) {
    bits &= ~(1u << pos);
    return *this;
}

Byte& Byte::toggleBit(int pos) {
    bits ^= (1u << pos);
    return *this;
}

Byte& Byte::invertBit() {
    bits = ~bits;
    return *this;
}


/**
  Byte& shl(int steps);
  Byte& shr(int steps);
  explicit operator uint8_t();
  bool operator[](std::size_t idx);
*/


bool operator==(const Byte& left, const Byte& right){
#ifdef DEBUG
println("operator== left=.bits", left.bits, " right=.bits", right.bits);
#endif
  return left.bits == right.bits;
}

bool operator!=(const Byte& left, const Byte& right){
#ifdef DEBUG
println("operator!= left=.bits", left.bits, " right=.bits", right.bits);
#endif
  return !operator==(left, right);
}


bool operator<(const Byte& left, const Byte& right){
#ifdef TRACE
println("operator< left=.bits", left.bits, " right=.bits", right.bits);
#endif
  return left.bits < right.bits;
}

  ///bool operator<=>(const Byte& other);


std::string as_string(const Byte& b){
  std::string s("0b");
  for(int i=0; i<8;i++) {
     s += b.bits & (1<<i) ? '1' : '0';
  }
  return s;
}
