#include "../90_aux_src/helpers/println.hpp"
#include <string>

void printInfoFor(std::string town, unsigned int population, bool hasUniversity) {

    std::string pop = std::to_string(population);
    std::string hasUni = hasUniversity ? "hat eine Uni" : "hat keine Uni";
    std::string output = "Die Stadt " + town + " hat " + pop + " Einwohner und " + hasUni;
    println(output);
}

int polynom1(int x) {
    return (x-1) * (x-2) * (x-3);
}

int isNero() {
    int count = 0;

    for(int i=0; i<10; i++) {
        if(polynom1(i) == 0) {
            count++;
        }
    }

    return count;
}

void isOfCharacterKind(char c, bool isAlphabetic, bool isNumeric, bool isUpperCase) {
    if(isalpha(c)) println(c, " is alpha ?: ", isAlphabetic);
    if(isdigit(c)) println(c, " is num ?: ", isNumeric);
    if(isupper(c)) println(c, " is UpperCase ?: ", isUpperCase);
}

void characterSequence(bool alphaLowerCase, bool alphaUpperCase, bool numeric) {
    std::string charSnake = "";

    if(alphaLowerCase) {
        for(char c='a'; c<='z'; c++) {
            charSnake += c;
        }
    }

    if(alphaUpperCase) {
        for(char c='A'; c<= 'Z'; c++) {
            charSnake += c;
        }
    }

    if(numeric) {
        for(char c='0'; c<= '9'; c++) {
            charSnake += c;
        }
    }

    println(charSnake);
}

int main() {

    printInfoFor("Emden", 70000, true);

    for(int i=0; i<10; i++) {
        println(polynom1(i));
    }

    println("Nullstellen in Polynom1: ", isNero());

    isOfCharacterKind('X', true, false, true);

    characterSequence(true, false, true);


  println("this program shows how to use println()");
  int i=1;
  println(i);           // type int
  double d=2.78;
  println(d);           // type double
  println("");          // just an empty line
  println("i=", i, " d=", d);// more than one
  print("i=", i);       // print all with separate statements
  print(" d=", d);      // no "ln" -> no newline
  println();            // just an empty line
  println("1.0 = ",1.0);
  println("10000.0 = ",10000.0);
  println("10000.125 = ",10000.125);
}

