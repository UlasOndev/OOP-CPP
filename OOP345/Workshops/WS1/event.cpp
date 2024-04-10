#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>  

namespace seneca {
    size_t g_sysClock = 0;
    size_t Event::counter = 0;  

    Event::Event() : startTime(0) {
        description[0] = '\0'; 
    }

    void Event::display() {
        std::cout << std::setw(2) << ++seneca::Event::counter << ". ";  

        if (description[0] == '\0') std::cout << "| No Event |\n";
        else {
            size_t hours = startTime / 3600;
            size_t minutes = (startTime % 3600) / 60;
            size_t seconds = startTime % 60;

            std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                << std::setw(2) << minutes << ":"
                << std::setw(2) << seconds << " => "
                << description << std::setfill(' ') << '\n';
        }
    }

    void Event::set(const char* desc) {
        if (desc != nullptr && desc[0] != '\0') {
            std::strcpy(description, desc);
            startTime = g_sysClock;
        }
        else description[0] = '\0';
    }

} 
