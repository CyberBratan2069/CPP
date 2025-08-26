/***********************************************************************************************************************
 * @author Christian Reiswich
 **********************************************************************************************************************/




#include "../90_aux_src/helpers/println.hpp"
#include <random>
#include "Byte.hpp"   /** struct Byte { uint8_t bits; // ...  }; */

/// invokes copy ctor for creation of b
void printByte(Byte b) {
  println("printByte()  b = ", b);
}

/// copy ctor for return or
/// copy ellision / RVO return value optimization
Byte randomByte() {
    std::uniform_int_distribution<> d(0, 255);
    std::random_device r;
    std::mt19937 gen(r());
    return {static_cast<uint8_t>(d(gen))};
}

int main(){
    println("1111111111111111111111111");
    Byte b1;            // default ctor
    printByte(b1);

    println("\n2222222222222222222222222");
    Byte b2(0xfe);      // ctor unsigned int
        println("b2 = ", b2);
        println("b2 = ", b2.operator<<(1));
        println("b2 shift left    = ", b2.shl(2));
        println("b2 shift right   = ", b2.shr(2));
        println("b2 set bit(2)    = ", b2.setBit(2));
        println("b2 get bit(2)    = ", b2.getBit(2));
        println("b2 clear bit(2)  = ", b2.clearBit(2));
        println("b2 toggle bit(2) = ", b2.toggleBit(2));
        println("b2 invert bit(2) = ", b2.invertBit());


    println("\n3333333333333333333333333");
    Byte b3=b2;         // copy ctor
    printByte(b3);


    println("\n4444444444444444444444444");
    Byte b4 = 0xfc;     // ctor unsigned int, copy ctor
    printByte(b4);


    println("\n5555555555555555555555555");
    b1 = b2;            // operator =
    printByte(b1);


    println("\n6666666666666666666666666");
    b4 = 23;            // implicit cast (ctor unsigned int), then copy ctor
    printByte(b4);


    println("\n7777777777777777777777777");
    if(b1 == b2){       // operator ==
      println("operator== seems to work");
    }


    println("\n8888888888888888888888888");
    if(b4 < b3){        // operator <
      println("operator< seems to work");
    }


    println("\n9999999999999999999999999");
    Byte b5 = randomByte();                 // ctor uint, copy return value, copy to b5
    printByte(b5);


    println("\naaaaaaaaaaaaaaaaaaaaaaaaa");
    printByte(b5);


    println("\nbbbbbbbbbbbbbbbbbbbbbbbbb");
    Byte arr[7];
    for(auto bytes : arr) {
        printByte(bytes);
    }


    return 0;
}
