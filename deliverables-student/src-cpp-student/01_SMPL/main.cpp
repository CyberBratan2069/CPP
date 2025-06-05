// this is "src-cpp-student/01a_SMPL/main.cpp"

//#include "/println.hpp" // declaration/definition of println()
#include "../90_aux_src/helpers/println.hpp"


// declare functions; will be defined below
void printValues(int first, int last);
int function(int);

int main(){           // program entry point
  printValues(0,9);
  return 0;           // no error occoured
}

int function(int x){
  int y = 2 * x - 4; 
  return y;
}

void printValues(int first, int last){
  println("first=", first, "  last=", last);
  int k=first;
  while(k<=last){
    int y=function(k);
    println("y(",k,")=",y);
    k = k+1;
  }
}
