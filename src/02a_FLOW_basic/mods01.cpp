/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created 15 Mar. 2025
 **********************************************************************************************************************/


#include "../90_aux_src/helpers/AnsiConsole.hpp"
#include "../90_aux_src/helpers/printSteps.hpp"
#include <thread>
#include <chrono>
#include <future>
#include <functional>

void start_Sequence(void){nop;
    nop;
    nop;
    for(int i=0; i<12; i++) nop;
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
