// Multipli Definition => Mehrfach definierte Variablen
// Undefined Indentifier => Main ruft eine Funktion auf die garnicht existiert
// Undefined Reference => Main ruft eine Funtkion auf die keine Werte hat

//Compiling with => clang++ -std=c++11 main.cpp example.cpp -o example


#include "polynom1.h"
#include "polynom2.h"
#include "../90_aux_src/helpers/println.hpp"



int main() {
	
	println("polynom1: ");
	for(int i=0; i<=10; i++) {
		println(i, ": ", polynom1(i));
	}

	//println("polynom1: ", polynom1());

	println("polynom2: ");
	for(int i=0; i<=10; i++) {
		println(i, ": ", polynom2(i));
	}


	//println(polynom1(1));
	//println(polynom1());
}