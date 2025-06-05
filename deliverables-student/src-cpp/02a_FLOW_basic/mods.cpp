#include "../90_aux_src/helpers/AnsiConsole.hpp"
#include "../90_aux_src/helpers/printSteps.hpp"
#include <thread>
#include <chrono>
#include <future>
#include <functional>



void start_Sequence(void){nop;
  nop;
  nop;
  nop;
  nop;
  nop;
  nop;
}



typedef void (*voidFunc)();

void performPattern(voidFunc func, std::string title){
  TITLE(title);
  func();
  printCommands(__FILE__);
  resetCommands();
  getchar();
}

int main(/*int argc, const char * argv[]*/) {
  performPattern(start_Sequence, "Sequence");


  return 0;
}
