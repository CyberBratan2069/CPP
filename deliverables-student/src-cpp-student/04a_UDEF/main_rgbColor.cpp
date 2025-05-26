#include "println.hpp"
#include "RgbColor.hpp"


void foobar(double d){
  println("foobar(double d), d = ", d);
}

int main(){
  RgbColor pureBlue(0xff);
  println("pureBlue = ", pureBlue);
  
  RgbColor pureRed(0xff0000);
  println("pureRed = ", pureRed);
  
  RgbColor grey(127,127,127); // red, green, blue
  println("grey = ", grey);
  
  RgbColor mix1 = pureBlue + pureRed;
  println("mix1 = ", mix1);

  RgbColor black(0);
  if(!black){
    println("fine, black = ", black, " is " , static_cast<bool>(black));
  }

  if(mix1 > pureRed){
    println("mix1 is greater than ", pureRed);
  } else {
    println("mix1 is less/equal than ", pureRed);
 }

#ifdef LEVEL_C
  RgbColor x(0x010101);
  println("x = ", x);
  RgbColor a = x;
  RgbColor b = x++;
  RgbColor c = x;
  println("a = ", a);
  println("b = ", b);
  println("c = ", c);


  RgbColor y(0x010101);
  println("y = ", y);
  RgbColor d = y;
  RgbColor e = ++y;
  RgbColor f = y;
  println("d = ", d);
  println("e = ", e);
  println("f = ", f);
  
  if((b==a) && (e==f)){
   println("fine++");
  }else{
   println("error++");
  }
  
  RgbColor otw(0x123456);
  println("otw.luminosity() = ", static_cast<unsigned int>(otw.luminosity()));
  println("otw.negated() = ", otw.negated());
  foobar(static_cast<double>(otw));
#endif
  return 0;
}

