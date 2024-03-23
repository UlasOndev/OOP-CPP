/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include <iostream>
#include <cstring>

namespace sdds {

    Menu::Menu(const char* content) : menuContent(nullptr), numOptions(0), validMenu(false) {
    if (content && strlen(content) > 0) {
        int tabs = 0;
        for (int i = 0; content[i] != '\0'; i++) {
            if (content[i] == '\t') {
                tabs++;
            }
        }
        numOptions = tabs + 1;

        if (numOptions <= 15) {
            menuContent = new char[strlen(content) + 1];
            strcpy(menuContent, content);
            validMenu = true;
        }
    }
}

Menu::~Menu() {
    delete[] menuContent;
}

void Menu::displayMenu() const {
    std::cout << std::endl;

    char* menuCopy = new char[strlen(menuContent) + 1];
    strcpy(menuCopy, menuContent);

    char* menuItem = strtok(menuCopy, "\t");
    int listNo = 1;

    while (menuItem != nullptr) {
        std::cout << listNo << "- " << menuItem << "\n";
        menuItem = strtok(nullptr, "\t");
        listNo++;
    }

    delete[] menuCopy;

    std::cout << "---------------------------------\n0- Exit\n> ";
}


unsigned int Menu::run() const {
    if (!validMenu) {
        std::cout << "Invalid Menu!\n";
        return 0;
    }

    displayMenu();
    int selection;
    while (true) {
        if (std::cin >> selection) {
            if (selection < 0 || selection > numOptions) {
                std::cout << "Value out of range [0<=val<=" << numOptions << "]: ";
            }
            else {
                break;
            }
        }
        else {
            std::cout << "Invalid Integer, retry: ";
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }
    }
    return selection;
}
}