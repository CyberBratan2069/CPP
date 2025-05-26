#include "AnsiConsole.hpp"
//#include "println.hpp"
#include <time.h>
#include "printSteps.hpp"

typedef void (*voidFunc)();


void end(){
nop;}

void func_1(){
nop;}

void func_2(){
nop;}

void start_call_func(void){nop; 
  nop;
  nop;
  for (int i=0;i<10;i++) func_1();
  nop;
  nop;
end();}

voidFunc func_X;

void start_call_func_i(void){nop; 
  nop;
  nop;
  for (int i=0;i<10;i++) func_X();
  nop;
  nop;
end();}



void performPattern(voidFunc func, std::string title){
  TITLE(title);
  func();
  printCommands(__FILE__);
  resetCommands();
  getchar();
}

int main(/**int argc , const char * argv[]*/) {
  performPattern(start_call_func, "Direct Function Call");
  time_t now;
  time(&now);
  if (now & 0x02) {
    func_X = func_2;
  } else {
    func_X = func_1;
  }
  performPattern(start_call_func_i, "Indirect Function Call");


  return 0;
}
