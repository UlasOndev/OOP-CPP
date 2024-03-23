/* Citation and Sources...
Final Project Milestone 5
Module: iProduct
Filename: iProduct.h
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
#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H

#include <iostream>

using namespace std;

namespace sdds {
    class iProduct {
    public:
        virtual ~iProduct() {} // Virtual destructor for proper cleanup in derived classes.

        // Pure virtual functions defining the interface.
        virtual int readSku(istream& istr) = 0; // Reads SKU from input stream.
        virtual int operator-=(int qty) = 0; // Decrements quantity by specified amount.
        virtual int operator+=(int qty) = 0; // Increments quantity by specified amount.
        virtual operator double() const = 0; // Conversion to double (possibly for calculations).
        virtual operator bool() const = 0; // Conversion to bool (possibly for validity checks).
        virtual int qtyNeeded() const = 0; // Returns the quantity needed.
        virtual int qty() const = 0; // Returns the current quantity.
        virtual char* getItemDesc() const = 0; // Returns item desc.
        virtual void linear(bool isLinear) = 0; // Sets display mode (linear/non-linear).
        virtual ofstream& save(ofstream& ofstr) const = 0; // Saves object state to a file.
        virtual ifstream& load(ifstream& ifstr) = 0; // Loads object state from a file.
        virtual ostream& display(ostream& ostr) const = 0; // Displays product information.
        virtual istream& read(istream& istr) = 0; // Reads product information from input stream.
        virtual bool operator==(int sku) const = 0; // Compares SKU for equality.
        virtual bool operator==(const char* description) const = 0; // Compares description for equality.
    };

    // Overloaded stream operators for iProduct class.
    ostream& operator<<(ostream& ostr, const iProduct& product); // Output operator.
    istream& operator>>(istream& istr, iProduct& product); // Input operator.

}
#endif // !SDDS_IPRODUCT_H