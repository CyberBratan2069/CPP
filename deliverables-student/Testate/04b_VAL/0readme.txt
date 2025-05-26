

steps to show:

for 1) and 2): 
- have -DTRACE disabled in build.sh 
- do not show Byte.hpp nor Byte.cpp, 
- show short comment /* struct Byte { uint8_t bits; // ...


1) in main_byte.cpp have "typedef int Byte;" active (not "include Byte.hpp")
   This shows that the code works with ints

   
2) in main_byte.cpp have "include Byte.hpp" active (not "typedef int Byte;")
   this proves "struct Byte behaves like int"


3) enable -DTRACE in build.sh
   this shows traces of automatically invoked special functions


4) (Level C) show "= default" in Byte.hpp

5) (Level C) use "-std=c++17" instead of "-std=c++14 -fno-elide-constructors" in build.sh 







