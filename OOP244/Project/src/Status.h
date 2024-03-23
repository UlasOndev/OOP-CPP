/* Citation and Sources...
Final Project Milestone 5
Module: Status
Filename: Status.h
Version 1.0
Author	Ulas Ondev
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef STATUS_H
#define STATUS_H

#include <iostream>

namespace sdds {
    class Status {
        char* m_description;
        int m_code;

    public:
        // Constructors
        Status(const char* description = nullptr, int code = 0);
        Status(const Status& other);

        // Assignment operators
        Status& operator=(const Status& other);
        Status& operator=(const char* description);
        Status& operator=(int code);

        // Type conversion operators
        operator const char* () const;
        operator int() const;
        operator bool() const;

        // Clear method
        Status& clear();

        // Destructor
        ~Status();
    };

    // Helper insertion operator
    std::ostream& operator<<(std::ostream& os, const Status& status);
}

#endif // !SDDS_STATUS_H
