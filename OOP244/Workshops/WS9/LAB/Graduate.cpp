#define _CRT_SECURE_NO_WARNINGS
#include "Graduate.h"
#include <cstring>
#include <iostream>

namespace sdds {

    Graduate::Graduate() : Student(), thesisTitle(nullptr), supervisor(nullptr) {}

    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* thesis)
        : Student(name, age), thesisTitle(nullptr), supervisor(nullptr) {

        if (thesisTitle != nullptr) {
            this->thesisTitle = new char[strlen(thesisTitle) + 1];
            strcpy(this->thesisTitle, thesisTitle);
        }

        if (thesis != nullptr) {
            this->supervisor = new char[strlen(thesis) + 1];
            strcpy(this->supervisor, thesis);
        }
    }

    Graduate::Graduate(const Graduate& other) : Student(other) {
        thesisTitle = nullptr;
        supervisor = nullptr;
        *this = other; 
    }

    Graduate& Graduate::operator=(const Graduate& other) {
        if (this != &other) {
            Student::operator=(other); 

            delete[] thesisTitle;
            delete[] supervisor;

            thesisTitle = nullptr;
            supervisor = nullptr;

            if (other.thesisTitle != nullptr) {
                thesisTitle = new char[strlen(other.thesisTitle) + 1];
                strcpy(thesisTitle, other.thesisTitle);
            }

            if (other.supervisor != nullptr) {
                supervisor = new char[strlen(other.supervisor) + 1];
                strcpy(supervisor, other.supervisor);
            }
        }
        return *this;
    }

    Graduate::~Graduate() {
        delete[] thesisTitle;
        delete[] supervisor;
    }

    void Graduate::display() const {
        Student::display();
        std::cout << "Thesis Title: " << (thesisTitle ? thesisTitle : "No thesisTitle") << std::endl;
        std::cout << "Supervisor: " << (supervisor ? supervisor : "No title") << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
}
