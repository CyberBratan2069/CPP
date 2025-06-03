#include "../../90_aux_src/helpers/println.hpp"
#define numValues 10

// this declares an alias for type <see below>, which is called calctype
// FROM_INT makro is needed to create values in main()
#ifdef CALCTYPE_INT
typedef int T_calc;
#define FROM_INT(x) x                     // convert int to T_calc
#endif

#ifdef CALCTYPE_DOUBLE
typedef double T_calc;
#define FROM_INT(x) double(x*1.0)         // convert int to T_calc (aka double)
#endif

#ifdef CALCTYPE_RATIONAL
#include "RationalNumber.hpp"           // location 1  FIXME: TODO TBD 
typedef RationalNumber T_calc;        /// location 2   FIXME:   TODO TBD
#define FROM_INT(x) RationalNumber(x,1)   // convert int to T_calc (aka RationalNumber),  implicit type conversion via constructor 
#endif

#ifdef CALCTYPE_RGB
#include "RgbColor.hpp"
typedef RgbColor T_calc;
//#define FROM_INT(x) RgbColor(x)
#define FROM_INT(x) RgbColor((x) | (x)<<8 | (x)<<16)
#endif



void printMinMax(T_calc values[], int length){
  T_calc minimum = values[0];
  T_calc maximum = values[0];
  //T_calc sum = FROM_INT(values[0]); // calculate average
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
  T_calc values[numValues];
  for(int i=0; i<numValues; i++){
    values[i] = FROM_INT(5+i*7);
  }
  printMinMax(values, numValues);
  return 0;
}
