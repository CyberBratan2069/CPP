//
// Created by Christian Reiswich on 6/11/25.
//
#include <iostream>
#include <csignal>
#include <unistd.h>

void ISR_Handler(int signals) {
    std::cout << "Receive signals: " << signals << std::endl;
    std::cout << "Program is ended" << std::endl;
    exit(0);
}

int main() {
    signal(SIGINT, ISR_Handler);

    std::cout << "End with Strg+C" << std::endl;

    while(true) {
        std::cout << "." << std::flush;
        sleep(1);
    }

    return 0;
}