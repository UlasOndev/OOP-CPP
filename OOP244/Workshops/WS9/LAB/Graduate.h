#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

namespace sdds {
    class Graduate : public Student {
    private:
        char* thesisTitle; 
        char* supervisor;

    public:

        Graduate();
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
        Graduate(const Graduate& other);
        Graduate& operator=(const Graduate& other);
        ~Graduate();
        void display() const;

    };

}

#endif //!SDDS_GRADUATE_H
