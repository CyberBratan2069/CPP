// file: RationalNumber.hpp
#include <iostream>

struct RationalNumber{
	int zaehler;
	int nenner;
  RationalNumber();
  RationalNumber(int z);
  RationalNumber(int z, int n);
  RationalNumber& operator/=(const RationalNumber&);
  RationalNumber& operator*=(const RationalNumber&);
  RationalNumber& operator=(const RationalNumber&);
  RationalNumber& operator++();    //  prefix: ++r
  RationalNumber  operator++(int);  // postfix: r++
};

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right);
RationalNumber operator+ (RationalNumber left, RationalNumber right);
bool operator< (RationalNumber left, RationalNumber right);
bool operator> (RationalNumber left, RationalNumber right);
std::string as_string(RationalNumber);  // for println()
//std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted); // for cout
