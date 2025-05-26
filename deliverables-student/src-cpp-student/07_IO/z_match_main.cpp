#include "../90_aux_src/helpers/println.hpp"
#include "z_match_elements.hpp"
#include "z_match_patterns.hpp"


int loglevel = 0;  /// needed by log.hpp


void test_1(){
  test_elements();
  test_patterns();
}


int main(){

  test_1();
  
  std::string h1 = "Hello";
   /** 
  println("h1 a", match_hello(h1, 0, h1.length()));
  println("h1 b", match_hello(h1, 1, h1.length()));

 
  std::string h3 = "HelloHello";
  int ml;
  ml=match_hello(h3, 0, h3.length());
  println("h3 a", ml);
  ml=match_hello(h3, 0+ml, h3.length());
  println("h3 b", ml);
      */

  /** std::string h2 = "HELLO";
  println("h2 a", match_hello(h2, 1, h2.length()-1));


*/


  std::string hello_w    = "Hello,World!";
  std::string hello_one  = "Hello,James!";
  std::string hello_many = "Hello,Bruce,Lemmy,Bon!";

  println("match_greet_world()");
  println("mgw a", match_greet_world(hello_w, 0, hello_w.length()-1));
  println("mgw b", match_greet_world(hello_one, 0, hello_one.length()-1));

  println("match_greet_match_greet_one()");
  println("mgo a", match_greet_one(hello_one, 0, hello_one.length()-1));

  println("match_greet_many()");
  println("mgm a", match_greet_many(hello_one, 0, hello_one.length()-1));
  println("mgm b", match_greet_many(hello_many, 0, hello_many.length()-1));

  return 0;
}
