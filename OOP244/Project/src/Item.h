/* Citation and Sources...
Final Project Milestone 5
Module: Item
Filename: Item.h
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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "iProduct.h"
#include "Status.h"

namespace sdds {
    class Item : public iProduct {
        double m_price;
        int m_quantity;
        int m_neededQty;
        char* m_desc;
        bool m_Linear;

    protected:
        Status m_status; // Status of the item
        int m_sku = 0; // Stock Keeping Unit (SKU) of the item

        // Helper function to determine display type
        bool linear() const { return m_Linear; };

    public:
        // Default constructor initializing member variables
        Item();

        // Copy constructor
        Item(const Item& other);

        // Assignment operator overload
        Item& operator=(const Item& other);

        // Virtual destructor
        virtual ~Item();

        // Accessors for quantity needed and available
        char* getItemDesc()const;
        int qtyNeeded() const override;
        int qty() const override;

        // Conversion operators
        operator double() const override;
        operator bool() const override;

        // Compound assignment operators for quantity adjustment
        int operator-=(int qty) override;
        int operator+=(int qty) override;

        // Function to set display type
        void linear(bool display_type) override;

        // Clear function to reset object state
        void clear();

        // Comparison operators
        bool operator==(int sku) const override;
        bool operator==(const char* description) const override;

        // File stream functions for saving, displaying, loading, and reading
        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ostream& display(std::ostream& ostr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;
        std::istream& read(std::istream& istr) override;

        // Read SKU from input stream
        int readSku(std::istream& istr) override;
 
    };
}

#endif // !SDDS_ITEM_H