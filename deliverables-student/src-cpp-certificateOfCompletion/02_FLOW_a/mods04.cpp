//
// Created by Christian Reiswich on 3/17/25.
//
#include "../../90_aux_src/helpers/println.hpp"


bool isLeapYear(unsigned int year) {
    if(year%400==0) {
        println(year, " ist Schaltjahr");
        return true;
    }
    if(year%100==0){
        println(year, " ist kein Schaltjahr");
        return true;
    };
    if(year%4==0) {
        println(year, " ist Schaltjahr");
        return true;
    }
    return false;
}

void FizzBuzz(int max) {
    for(int i=0; i<max; i++) {
        if(i%3==0) println("Fizz");
        if(i%5==0) println("Buzz");
        if(i%3==0 && i%5==0) println("FizzBuzz");
        else println(i);
    }
}


int main() {

    for(int i=1582; i<=2052; i++) {
        isLeapYear(i);
    }

    FizzBuzz(30);

}