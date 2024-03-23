/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
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
#ifndef MENU_H
#define MENU_H

namespace sdds {

    class Menu {
    private:
        char* menuContent; // Dynamically allocated text holding menu options
        int numOptions; // Number of options in the menu
        bool validMenu; // Flag to determine if the menu is valid

        // Private helper methods
        void displayMenu() const;

    public:
        // Constructor and Destructor
        Menu(const char* menuContent);
        ~Menu();

        // Rule of Three - Disallow copy and assignment
        Menu(const Menu& other) = delete;
        Menu& operator=(const Menu& other) = delete;

        // Public method
        unsigned int run() const;
    };
}
#endif // !SDDS_MENU_H
