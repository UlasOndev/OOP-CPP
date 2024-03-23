#include <iostream>
#include <cstring>
#include "Train.h"

namespace sdds {

    Train::Train() {
        name = nullptr;
        passengers = -1;
        departureTime = -1;
    }

    Train::Train(const char* name, int passengers, int departureTime) {
        initialize();
        if (name && name[0] != '\0' && passengers >= 0 && passengers <= MAX_NO_OF_PASSENGERS && validTime(departureTime)) {
            set(name, passengers, departureTime);
        }
    }

    Train::~Train() {
        finalize();
    }

    void Train::initialize() {
        if (name) {
            delete[] name;
            name = nullptr;
        }
        passengers = -1;
        departureTime = -1;
    }

    bool Train::validTime(int value) const {
        int minute = value % 100;
        return (value >= MIN_TIME && value <= MAX_TIME && minute <= 59);
    }

    bool Train::validNoOfPassengers(int value) const {
        return (value >= 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* newName) {
        finalize();
        if (newName && newName[0] != '\0') {
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        }
    }

    void Train::set(int noOfPassengers, int newDepartureTime) {
        if (validNoOfPassengers(noOfPassengers) && validTime(newDepartureTime)) {
            passengers = noOfPassengers;
            departureTime = newDepartureTime;
        }
        else {
            passengers = -1;
            departureTime = -1;
        }
    }

    void Train::set(const char* newName, int noOfPassengers, int newDepartureTime) {
        set(newName);
        set(noOfPassengers, newDepartureTime);
    }

    void Train::finalize() {
        delete[] name;
        name = nullptr;
        passengers = -1;
        departureTime = -1;
    }

    bool Train::isInvalid() const {
        return (name == nullptr || passengers == -1 || departureTime == -1);
    }

    int Train::noOfPassengers() const {
        return passengers;
    }

    const char* Train::getName() const {
        return (name != nullptr) ? name : "";
    }

    int Train::getDepartureTime() const {
        return departureTime;
    }

    void Train::display() const {
        if (isInvalid()) {
            std::cout << "Train in an invalid State!" << std::endl;
        }
        else {
            std::cout << "NAME OF THE TRAIN:    " << getName() << std::endl;
            std::cout << "NUMBER OF PASSENGERS: " << noOfPassengers() << std::endl;
            std::cout << "DEPARTURE TIME:       " << getDepartureTime() << std::endl;
        }
    }

    bool Train::load(int& notBoarded) {
        notBoarded = 0;
        int newPassengers;
        std::cout << "Enter number of passengers boarding:" << std::endl;
        std::cout << "> ";
        std::cin >> newPassengers;
        if (newPassengers <= MAX_NO_OF_PASSENGERS - passengers) {
            passengers += newPassengers;
            return true;
        }
        else {
            notBoarded = newPassengers - (MAX_NO_OF_PASSENGERS - passengers);
            passengers = MAX_NO_OF_PASSENGERS;
            return false;
        }
    }

    bool Train::updateDepartureTime() {
        int newTime;
        std::cout << "Enter new departure time:" << std::endl;
        std::cout << "> ";
        std::cin >> newTime;
        if (validTime(newTime)) {
            departureTime = newTime;
            return true;
        }
        else {
            departureTime = -1;
            return false;
        }
    }

    bool Train::transfer(const Train& from) {
        if (!isInvalid() && !from.isInvalid()) {
            char* combinedName = new char[strlen(name) + strlen(from.name) + 3];
            strcpy(combinedName, name);
            strcat(combinedName, ", ");
            strcat(combinedName, from.name);

            int totalPassengers = passengers + from.passengers;

            if (totalPassengers <= MAX_NO_OF_PASSENGERS) {
                passengers = totalPassengers;
                delete[] name;
                name = combinedName;
                return true;
            }
            else {
                int notTransferred = totalPassengers - MAX_NO_OF_PASSENGERS;
                passengers = MAX_NO_OF_PASSENGERS;
                delete[] name;
                name = combinedName;
                std::cout << "Train is full; " << notTransferred << " passengers of " << from.name << " could not be boarded!" << std::endl;
                return true;
            }
            
        }
        return false;
    }
}
