//MPINCLUDE1
#include "logger.hpp"
#include <iostream>
#include <cassert>

int binary_search(std::string s, char c);
int linear_search(std::string s, char c);

//MPINCLUDE2



// "Although the basic idea of binary search is comparatively straightforward, 
// the details can be surprisingly tricky" -- Donald Knuth
/// searches recursively; left and right have to be valid positions in s
int binary_search_rec(std::string s, char c, unsigned int left, unsigned int right){
  log_msg(DEBUG, "binary_search s=" + s + " left=" + std::to_string(left) + " right=" + std::to_string(right) + " c=" + c);
  assert(left <= right);
  /// we are finnished if (right-left) <=1
  /// so, either we have found it or return -1
  if (left==right){ /// s[left] is the same as s[right]. it might be c or not
                    /// eg s="klmno", c='m', left=2, right=2 
    if (s[left] == c){
      log_msg(DEBUG, std::string("binary_search_rec found it! left=") + std::to_string(left));
      return left;
    } else {
      log_msg(WARNING, std::string("binary_search_rec didn't find c=") + c);
      return -1;
    }
  } else if (left==right-1){ /// left and right are direct neighbors
                             /// eg s="klmnoX", c='m', left=2, right=3 
    if (s[left] == c){
      log_msg(DEBUG, std::string("binary_search_rec found it! left=") + std::to_string(left));
      return left;
    } else if (s[right] == c){
      log_msg(DEBUG, std::string("binary_search_rec found it! right=") + std::to_string(right));
      return right;
    } else {
      log_msg(WARNING, std::string("binary_search_rec didn't find c=") + c);
      return -1;
    }
  }
  /// c wasn't found above -- let's search recursively in left half or right half  
  unsigned int middle = left + (right-left)/2;
  if (s[middle] < c){
    return binary_search_rec(s, c, middle, right);
  } else {  
    return binary_search_rec(s, c, left, middle);
  }  
}
   
           
int binary_search(std::string s, char c){
  return binary_search_rec(s, c, 0, s.length()-1);
}

int linear_search(std::string s, char c){
  log_msg(DEBUG, "linear_search s=" + s);
  int result = -1;
  for(unsigned int i=0; i < s.length(); i++){
    if (s[i] == c) {
      log_msg(DEBUG, std::string("linear_search found it! i=") + std::to_string(i));
      result = i;
      break;
    } 
  }
  if(result == -1){
    log_msg(WARNING, std::string("linear_search didn't find c=") + c);
  }
  return result;
}

void test_search1(std::string text, char c){
  int pos1 = linear_search(text, c);
  int pos2 = binary_search(text, c);
  if (pos1 == pos2) { 
    log_msg(DEBUG, "binary_search OK!     s=" + text + " c=" + c); 
  } else {
    log_msg(ERROR, "binary_search BROKEN! s=" + text + " c=" + c); 
  }
}

void test_search(){
  std::string text = "abcdefghijklmnopqrstuvwxyz";
  test_search1(text,'a');
  test_search1(text,'b');
  test_search1(text,'c');
  test_search1(text,'d');
  test_search1(text,'k');
  test_search1(text,'l');
  test_search1(text,'m');
  test_search1(text,'n');
  test_search1(text,'w');
  test_search1(text,'x');
  test_search1(text,'y');
  test_search1(text,'z');
}

//MPINCLUDE3
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
//MPINCLUDE4

