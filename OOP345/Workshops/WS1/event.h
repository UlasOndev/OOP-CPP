#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <cstddef>  

namespace seneca {
    extern size_t g_sysClock;

    class Event {
    static size_t counter; 
    char description[128]; 
    size_t startTime; 
    public:
        Event();
        void display();
        void set(const char* desc = nullptr);
    };
}

#endif // SENECA_EVENT_H
