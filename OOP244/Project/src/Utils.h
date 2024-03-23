/***********************************************************************
// Final project Milestone 5
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
   Ulas Ondev        2023-11-04      
***********************************************************************/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include "Item.h"

namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);

        // Copy string safety

        void copyString(char* dest, size_t destSize, const char* src);

        // Get an integer from user input with an optional prompt
        int getInt(const char* prompt = "\0");

        // Get an integer within a specified range with an optional prompt
        int getInt(int min, int max, const char* prompt = nullptr);

        // Get an integer from a file stream
        int getInt(std::istream& file);

        // Get a double from user input with an optional prompt
        double getDouble(const char* prompt = "\0");

        // Get a double within a specified range with an optional prompt
        double getDouble(double min, double max, const char* prompt = nullptr);

        // Get a C-style string from a specified input stream and delimiter
        char* getCString(std::istream& input, char delimiter = '\n');

        // Get a C-style string from user input and delimiter
        char* getCString(const char* prompt = "\0", char delimiter = '\n');

    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H