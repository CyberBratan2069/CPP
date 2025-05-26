#include "logger.hpp"
#include <iostream>
#include <cassert>

int binary_search(std::string s, char c);
int linear_search(std::string s, char c);

int main(int argc, char* argv[]){
  std::cout << "Welcome! You may append append -l0 -l1 -l2 or -l3 to a.out" << std::endl;
  setup_logger(argc, argv);
  //test_search();
  std::string text = "jklmnqpo"; //"abcdefghijklmnopqrstuvwxyz";
  char c = 'p';
  int pos1 = linear_search(text, c);
  int pos2 = binary_search(text, c);
  if (pos1 == pos2) { 
    log_msg(DEBUG, "binary_search OK!     text=" + text + " c=" + c); 
  } else {
    log_msg(ERROR, "binary_search BROKEN! text=" + text + " c=" + c); 
  }
  return 0;
}
