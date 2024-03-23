/* Citation and Sources...
Final Project Milestone 5
Module: Perishable
Filename: Perishable.h
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include <iostream>

#include "Date.h"
#include "Item.h"

namespace sdds {
    class Perishable : public Item {
        Date m_expiry_date; // Holds the expiry date for the perishable item
        const char* m_handling_instructions = nullptr; // Pointer to handling instructions for the item

    public:
        // Default constructor initializing expiry date
        Perishable() : m_expiry_date() {}

        // Copy constructor
        Perishable(const Perishable& other);

        // Returns a reference to the expiry date
        const Date& expiry();

        // Assignment operator overload
        Perishable& operator=(const Perishable& other);

        // Conversion to bool override
        operator bool() const override;

        // Destructor override
        ~Perishable() override;

        // Read SKU from input stream
        int readSku(std::istream& istr) override;

        // Save to output file stream
        std::ofstream& save(std::ofstream& ofstr) const override;

        // Display in output stream
        std::ostream& display(std::ostream& ostr) const override;

        // Load from input file stream
        std::ifstream& load(std::ifstream& ifstr) override;

        // Read from input stream
        std::istream& read(std::istream& istr) override;

        // Friend function overloads for stream operators
        friend std::ostream& operator<<(std::ostream& ostr, const Perishable& perishable_item) { return perishable_item.display(ostr); };
        friend std::istream& operator>>(std::istream& istr, Perishable& perishable_item) { return perishable_item.read(istr); };
    };
}


#endif // !SDDS_PERISHABLE_H
