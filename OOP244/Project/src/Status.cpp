/* Citation and Sources...
Final Project Milestone 5
Module: Status
Filename: Status.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include <cstring>

namespace sdds {
    Status::Status(const char* description, int code) : m_description(nullptr), m_code(code) {
        if (description != nullptr) {
            m_description = new char[strlen(description) + 1];
            strcpy(m_description, description);
        }
    }

    Status::Status(const Status& other) : m_description(nullptr) {
        *this = other;
    }

    Status& Status::operator=(const Status& other) {
        if (this != &other) {
            delete[] m_description;
            m_code = other.m_code;
            if (other.m_description != nullptr) {
                m_description = new char[strlen(other.m_description) + 1];
                strcpy(m_description, other.m_description);
            }
            else {
                m_description = nullptr;
            }
        }
        return *this;
    }

    Status& Status::operator=(const char* description) {
        delete[] m_description;
        if (description != nullptr) {
            m_description = new char[strlen(description) + 1];
            strcpy(m_description, description);
        }
        else {
            m_description = nullptr;
        }
        return *this;
    }

    Status& Status::operator=(int code) {
        m_code = code;
        return *this;
    }

    Status::operator const char* () const {
        return m_description;
    }

    Status::operator int() const {
        return m_code;
    }

    Status::operator bool() const {
        return (m_description == nullptr);
    }

    Status& Status::clear() {
        delete[] m_description;
        m_description = nullptr;
        m_code = 0;
        return *this;
    }

    Status::~Status() {
        delete[] m_description;
    }

    std::ostream& operator<<(std::ostream& os, const Status& status) {
        if (!status) {
            if (int(status) == 0);
            else os << "ERR#" << int(status) << ": ";
        }
        if (const char* desc = status) {
            os << desc;
        }
        return os;
    }
}
