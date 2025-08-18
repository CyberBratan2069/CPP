/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created 01 Mai. 2025
 * @last modified 06 Mai. 2025
 * @version 1.0
 * @brief
 **********************************************************************************************************************/


// file: RationalNumber.cpp
#include "RationalNumber.hpp"

RationalNumber addRationalNumbers(RationalNumber left, RationalNumber right){
	RationalNumber result;
	// add left and right
  if(left.getNenner() == right.getNenner()){
    result = RationalNumber(left.getZaehler()+right.getZaehler(), left.getNenner());
  }else{
    int z = left.getZaehler() * right.getNenner() + left.getNenner() * right.getZaehler();
    int n = left.getNenner() * right.getNenner();
    // TODO: simplify quotient
    result = RationalNumber(z, n);
  }
	return result;
}

RationalNumber::RationalNumber(int z, int n)
    : zaehler(z), nenner(n) {}

RationalNumber& RationalNumber::operator/=(const RationalNumber& other){
  this->zaehler *= other.nenner;
  this->nenner  *= other.zaehler;
  return *this;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& other){
  this->zaehler *= other.zaehler;
  this->nenner  *= other.nenner;
  return *this;
}

RationalNumber& RationalNumber::operator++(){     // prefix
  zaehler += nenner;
  return *this;
}

RationalNumber RationalNumber::operator++(int){  // postfix
  RationalNumber result = *this;
  return ++result;
}

RationalNumber operator+ (RationalNumber left, RationalNumber right){
	return addRationalNumbers(left, right);
}

bool operator< (RationalNumber left, RationalNumber right){
  return (1.0*left.getZaehler()/left.getNenner())<(1.0*right.getZaehler()/right.getNenner());
}

bool operator> (RationalNumber left, RationalNumber right){
  return (1.0*left.getZaehler()/left.getNenner())>(1.0*right.getZaehler()/right.getNenner());
}


// for println()
std::string as_string(RationalNumber r){
  std::string result = "(";
  result += std::to_string(r.getZaehler());
  result += "/";
  result += std::to_string(r.getNenner());
  result += ")";
  return result;
}

/*std::ostream& operator<< (std::ostream& os, RationalNumber &toBePrinted){
	os << "(" << toBePrinted.zaehler << "/"
	<< toBePrinted.nenner << ")";
	return os;
}*/
