#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"

namespace sdds {
    Student::Student() : name(nullptr), age(0) {} 

    Student::Student(const char* name, int age) : age(age) {
        if (name != nullptr) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr; 
        }
    }

    Student::Student(const Student& other) : age(other.age) {
        if (other.name != nullptr) {
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
        }
        else {
            this->name = nullptr; 
        }
    }

    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] this->name; 

            this->age = other.age; 

            if (other.name != nullptr) {
                this->name = new char[strlen(other.name) + 1];
                strcpy(this->name, other.name);
            }
            else {
                this->name = nullptr; 
            }
        }
        return *this;
    }

    Student::~Student() {
        delete[] name; 
    }

    void Student::display() const {
        std::cout << "Name: " << (name ? name : "No name") << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

}
