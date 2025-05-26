#include "z_match_elements.hpp"
#include "z_log.hpp"
#include <cassert>



std::string s_hello = "Hello";
std::string s_world = "World";

/// hello       ::= 'H' 'e' 'l' 'l' 'o'
size_t match_hello(std::string src, size_t offset, size_t max_offset){
  ///println("match_hello", " src='", src,"' offset=",offset, " max_offset=", max_offset, " src[offset]=", src[offset], " src[max_offset]=", src[max_offset]);
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  size_t h_offset = 0;
  while (h_offset < s_hello.length() && offset + h_offset < max_offset + 1 ){
     if (s_hello[h_offset] != src[offset+h_offset]) {
       return 0;
     }
     h_offset++;
  }
  ///println("match_hello", " src='", src,"' h_offset=",h_offset, " src[h_offset]=", src[h_offset]);
  return h_offset == s_hello.length() ? h_offset : 0;  
}

/// world       ::= 'W' 'o' 'r' 'l' 'd'
size_t match_world(std::string src, size_t offset, size_t max_offset){
  size_t h_offset = 0;
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  while ( h_offset < s_world.length() && offset + h_offset < max_offset + 1){
     if (s_world[h_offset] != src[offset+h_offset]) {
       return 0;
     }
     h_offset++;
  }
  return h_offset == s_world.length() ? h_offset : 0;  
}

/// COMMA       ::= ',' 
size_t match_COMMA(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  return src[offset] == ',' ? 1 : 0;
}

/// EXCL        ::= '!'
size_t match_EXCL(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  return src[offset] == '!' ? 1 : 0;
}



/// DIGIT       ::= '0' | '1' | '2' | ... | '9'
size_t match_DIGIT(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  char c = src[offset];
  if ( c >= '0' && c <= '9' ){
     return 1;
  } else {
     return 0;
  }
}

/// LETTER      ::= 'a' | 'b' | 'c' | ... | 'z' | 'A' | 'B' | 'C' | ... | 'Z'
size_t match_ALPHA(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  char c = src[offset];
  if ( (c >= 'a' && c <= 'z') ||  (c >= 'A' && c <= 'Z') ){
     return 1;
  } else {
     return 0;
  }
}

/// DIGITS      ::= DIGIT (DIGIT)*
size_t match_DIGITS(std::string src, size_t offset, size_t max_offset){
  ///println("match_DIGITS offset=",offset, " max_offset=", max_offset);
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  int match_len = 0;
  int is_digit = 0;
  do {
    is_digit = match_DIGIT(src, offset + match_len, max_offset);
    match_len += is_digit;
  } while (is_digit > 0 && (offset+match_len<=max_offset));
///  println("match_DIGITS", "src=", src, " match_len=",match_len," offset=",offset, " max_offset=", max_offset, " src[offset]=", src[offset], " src[max_offset]=", src[max_offset]);
  assert( offset+match_len <= max_offset+1 );
  return match_len;
}



void test_elements(){
  if (loglevel>1) println("test_literals()   begin");

  std::string d1 = "1";  

  assert( match_DIGITS(d1, 0, d1.length()-1) == d1.length());
  assert( match_DIGITS(d1, 0, d1.length()+0) == 0);
  assert( match_DIGITS(d1, 1, d1.length()-1) == 0);  

  std::string d2 = "abc2";  
  assert( match_DIGITS(d2, 3, d2.length()-1) == 1);

  assert( match_DIGITS("abcd123wxyz", 4, 10) == 3);

  assert( match_DIGITS("1", 0, 2) == 0);
  assert( match_DIGITS("12", 0, 2) == 0);
  assert( match_DIGITS("a", 0, 2) == 0);
  assert( match_DIGITS("ab", 0, 2) == 0);

  assert( match_DIGITS("H", 0, 2) == 0);
  assert( match_DIGITS("He", 0, 2) == 0);
  assert( match_DIGITS("x", 0, 2) == 0);
  assert( match_DIGITS("xx", 0, 2) == 0);

  
  std::string h1 = "Hello";  
  assert( match_hello(h1, 0, h1.length()-1) == h1.length());
  assert( match_hello(h1, 0, h1.length()+0) == 0);
  assert( match_hello(h1, 1, h1.length()-1) == 0);  
  assert( match_hello("-Hello-", 1, 6) == 5);

  assert( match_world("World", 0, 4) == 5);
  assert( match_world("World", 0, 5) == 0);
  assert( match_world("World", 1, 4) == 0);  
  assert( match_world("World--", 0, 6) == 5);
  assert( match_world("-World-", 1, 6) == 5);

  assert( match_COMMA(",", 0, 0) == 1);
  assert( match_COMMA(",", 0, 1) == 0);
  assert( match_COMMA(",", 1, 0) == 0);
  assert( match_COMMA(" , ", 1, 2) == 1);
  assert( match_COMMA("  ,", 2, 2) == 1);

  assert( match_EXCL("!", 0, 0) == 1);
  assert( match_EXCL("!", 0, 1) == 0);
  assert( match_EXCL("!", 1, 0) == 0);
  assert( match_EXCL(" ! ", 1, 2) == 1);
  assert( match_EXCL("  !", 2, 2) == 1);



  if (loglevel>1) println("test_literals()   end");
}
