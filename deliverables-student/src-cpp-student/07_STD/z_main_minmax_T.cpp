#include "println.hpp"

#define numValues 10

#include "RationalNumber.hpp"           
//#include "rgbColor.hpp"           



template<typename T_calc> 
void printMinMax(T_calc values[], int length){
  T_calc minimum = values[0];
  T_calc maximum = values[0];
  //T_calc sum = FROM_INT(0); // calculate average
  for(int i=1; i<length; i++){
    if (values[i] < minimum){
      minimum = values[i];
    }
    if (values[i] > maximum){
      maximum = values[i];
    }
  }
  println("minimum=", minimum, " maximum=", maximum);
}


int main(){
  int i_values[numValues];
  for(int i=0; i<numValues; i++){
    i_values[i] = (5+i*7);
  }
  printMinMax(i_values, numValues);
  
  double d_values[numValues];
  for(int i=0; i<numValues; i++){
    d_values[i] = (5+i*7);
  }
  printMinMax(d_values, numValues);
     
     
  RationalNumber r_values[numValues];
  for(int i=0; i<numValues; i++){
    r_values[i] = (5+i*7);
  }
  printMinMax(r_values, numValues);
     
/*  RgbColor c_values[numValues];
  for(int i=0; i<numValues; i++){
    c_values[i] = (5+i*7);
  }
  printMinMax(c_values, numValues);
  */   
  
  return 0;
}
