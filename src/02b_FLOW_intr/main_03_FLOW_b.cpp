#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include "../90_aux_src/helpers/AnsiConsole.hpp"
#include "../90_aux_src/helpers/printSteps.hpp"


const int maxSignals = 3;
const bool doPrintDebug = false;

struct TimeStamps {
    int slotsUsed;
    time_t slots[maxSignals];
};


volatile int j;
volatile TimeStamps timeStamps;
volatile sigset_t blockedSignals;

void ISR(int iarg);

void install_ISR(void)
{
    signal(SIGUSR1, ISR);
}

void ISR(int iarg)
{
    if(timeStamps.slotsUsed < maxSignals) // 3
    {
        nop;
        time((time_t*)&timeStamps.slots[timeStamps.slotsUsed++]);
        nop;
        nop;
    }
    nop;
}

void mainloop()
{
    for(int i=0; i<20; i++)
    {
        sigprocmask(SIG_BLOCK, (sigset_t *)&blockedSignals, NULL);
        int slotsUsed = timeStamps.slotsUsed;
        nop;
        sigprocmask(SIG_UNBLOCK, (sigset_t *)&blockedSignals, NULL);
        if(slotsUsed >= maxSignals)
        {
            break;
        }
    j=i;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void start_ISR()
{
    timeStamps.slotsUsed = 0;
    sigemptyset ((sigset_t *)&blockedSignals);
    sigaddset((sigset_t *)&blockedSignals, SIGUSR1);
    install_ISR();
    mainloop();

}

typedef void (*voidFunc)();

void performPattern(voidFunc func, std::string title)
{
    TITLE(title);
    func();
    printCommands(__FILE__);
    resetCommands();
    getchar();
}

int main(/*int argc, const char * argv[]*/) {
    performPattern(start_ISR, "ISR");
    return 0;
}