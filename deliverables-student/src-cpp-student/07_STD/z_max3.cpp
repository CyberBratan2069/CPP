#include "println.hpp"

template <typename T>
T max3(T a, T b, T c){
  if ( (a>b) && (a>c) ) {
    return a;
  } else if ( (b>a) && (b>c) ) {
    return b;
  } else {
    return c;
  }
}

int main(){
  int i1=1, i2=2, i3=3;
  int mi = max3(i1,i2,i3);
  println("max3(i1,i2,i3) == ", mi);
  double d1=1.0, d2=2.0, d3=3.0;
  double md = max3(d1,d2,d3);
  println("max3(d1,d2,d3) == ", md);
  return 0;
}
