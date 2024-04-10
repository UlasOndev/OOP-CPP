#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm> 
#include <iomanip>
#include "Utilities.h"

namespace seneca {
    char Utilities::m_delimiter = ' ';

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const { return m_widthField;}

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string nextToken;
        size_t delim_pos = 0;
        const std::string WHITESPACE = " \n\r\t\f\v";
        size_t start = 0;
        size_t end = 0;
        char delim = getDelimiter();
        delim_pos = str.find(delim, next_pos);
        if (delim_pos == std::string::npos) {
            nextToken = str.substr(next_pos);
            start = nextToken.find_first_not_of(WHITESPACE);
            end = nextToken.find_last_not_of(WHITESPACE);
            nextToken = nextToken.substr(start, end - start + 1);
            more = false;
            if (m_widthField < nextToken.length())
                m_widthField = nextToken.length();
        }
        else if (delim_pos == next_pos) {
            more = false;
            throw next_pos;
        }
        else {
            nextToken = str.substr(next_pos, delim_pos - next_pos);
            start = nextToken.find_first_not_of(WHITESPACE);
            end = nextToken.find_last_not_of(WHITESPACE);
            nextToken = nextToken.substr(start, end - start + 1);
            more = true;
            next_pos = delim_pos + 1;
            if (m_widthField < nextToken.length())
                m_widthField = nextToken.length();
        }
        return nextToken;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() { return m_delimiter;}
}