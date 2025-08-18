/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created 01 Mai. 2025
 * @last modified 06 Mai. 2025
 * @version 1.0
 * @brief
 **********************************************************************************************************************/


// file: RationalNumber.hpp
#ifndef RATIONALNUMBER_HPP
#define RATIONALNUMBER_HPP
#include <iostream>

class RationalNumber {
private:
	int zaehler;
	int nenner;

public:
  //RationalNumber();
  //RationalNumber(int z);
  RationalNumber(int z=0, int n=1);
  RationalNumber(const RationalNumber&) = default;
  RationalNumber& operator=(const RationalNumber&) = default;
  RationalNumber& operator/=(const RationalNumber&);
  RationalNumber& operator*=(const RationalNumber&);
  RationalNumber& operator++();    //  prefix: ++r
  RationalNumber  operator++(int);  // postfix: r++
  int getZaehler() const {
      return zaehler;
  }
  int getNenner() const {
      return nenner;
  }
};

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right);
RationalNumber operator+ (RationalNumber left, RationalNumber right);
bool operator< (RationalNumber left, RationalNumber right);
bool operator> (RationalNumber left, RationalNumber right);
std::string as_string(RationalNumber rationalNumber);  // for println()
//std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted); // for cout

#endif