/* Citation and Sources...
Final Project Milestone 5
Module: iProduct.h
Filename: iProduct.cpp
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
#include <iostream>
#include "iProduct.h"

using namespace std;

namespace sdds {

	ostream& operator<<(ostream& ostr, const iProduct& product) {
		return product.display(ostr);
	}

	istream& operator>>(istream& istr, iProduct& product) {
		return product.read(istr);
	}

}