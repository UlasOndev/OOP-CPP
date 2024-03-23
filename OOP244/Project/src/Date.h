/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H

const int MAX_YEAR_VALUE = 2030;  
const int MAX_MONTH_VALUE = 12;         

#include <iostream>

#include "Utils.h"    
#include "Status.h"   

namespace sdds {
    class Date {
        int m_year = 0; 
        int m_month = 0; 
        int m_day = 0; 
        Status status; 
        bool isSet = false; 
        bool m_formatted = true; 

        // Private helper functions
        bool validate(); // Validates the date
        int unique_date_value() const; // Calculates a unique date value

    public:
        // Constructors
        Date(); // Default constructor
        Date(int date_value); // Constructor from a date value
        Date(int year, int month, int day); // Constructor from year, month, and day

        // Comparison operators
        bool operator==(Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(Date& other) const;
        bool operator>(Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;

        // Conversion to bool operator
        operator bool() const;

        // Accessor for date status
        const Status& state() const;

        // Function to set date format
        Date& formatted(bool f);

        // Stream functions for writing and reading dates
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        std::ifstream& load(std::ifstream& ifstr);

    };
    // Overloaded stream operators for Data class.
    std::ostream& operator<<(std::ostream& ostr, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);
}


#endif // !SDDS_DATE_H