/* Citation and Sources...
Final Project Milestone 5
Module: Item
Filename: Item.cpp
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

#include <iomanip>
#include "Utils.h"
#include "Item.h"

namespace sdds {
	Item::Item() {
		m_sku = 0;
		m_price = 0;
		m_quantity = 0;
		m_neededQty = 0;
		m_desc = nullptr;
		m_Linear = false;
	}

	Item::Item(const Item& other) {
		if (other.operator bool() && other.m_desc != nullptr) {
			m_desc = new char[strlen(other.m_desc) + 1];
			strcpy(const_cast<char*>(m_desc), other.m_desc);

			m_Linear = other.m_Linear;
			m_price = other.m_price;
			m_quantity = other.m_quantity;
			m_neededQty = other.m_neededQty;
			m_sku = other.m_sku;
		}
		else {
			m_desc = nullptr;
			m_Linear = false;
			m_price = 0;
			m_quantity = 0;
			m_neededQty = 0;
			m_sku = 0;
		}
	}

	Item& Item::operator=(const Item& other) {
		if (this == &other) {
			return *this;
		}

		delete[] m_desc;

		if (other.operator bool()) {
			m_desc = new char[strlen(other.m_desc) + 1];
			strcpy(const_cast<char*>(m_desc), other.m_desc);

			m_Linear = other.m_Linear;
			m_price = other.m_price;
			m_quantity = other.m_quantity;
			m_neededQty = other.m_neededQty;
			m_sku = other.m_sku;
		}
		else {
			m_desc = nullptr;
			m_Linear = false;
			m_price = 0;
			m_quantity = 0;
			m_neededQty = 0;
			m_sku = 0;
		}

		return *this;
	}


	Item::~Item() {
		delete[] m_desc;
		m_desc = nullptr;
	}

	int Item::qtyNeeded() const {
		return m_neededQty;
	}

	int Item::qty() const {
		return m_quantity;
	}

	char* Item::getItemDesc() const {
		return m_desc;
	}

	Item::operator double() const {
		return m_price;
	}

	Item::operator bool() const {
		return (m_desc != nullptr && m_quantity > 0 && m_neededQty > 0 && m_price > 0 && m_sku > 0);
	}

	int Item::operator-=(int qty) {
		if (qty >= 0 && qty <= m_quantity)
			return m_quantity -= qty;
		else
			return 0;
	}

	int Item::operator+=(int qty) {
		if (qty >= 0)
			return m_quantity += qty;
		else
			return 0;
	}

	void Item::linear(bool display_type) {
		m_Linear = display_type;
	}

	void Item::clear() {
		m_status.clear();
	}

	bool Item::operator==(int sku) const {
		return m_sku == sku;
	}

	bool Item::operator==(const char* description) const {
		int desLen = strlen(description);
		int mDesLen = strlen(m_desc);

		for (int i = 0; i <= mDesLen - desLen; i++) {
			int j;

			for (j = 0; j < desLen; j++)
				if (m_desc[i + j] != description[j])
					break;

			if (j == desLen)
				return true;
		}

		return false;
	}

	std::ofstream& Item::save(std::ofstream& ofstr) const {
		if (operator bool()) {
			ofstr << m_sku << '\t' << m_desc << '\t' << m_quantity << '\t' << m_neededQty << '\t';
			ofstr.precision(4);
			ofstr << m_price;
		}

		return ofstr;
	}

	std::ostream& Item::display(std::ostream& ostr) const {
		if (m_status && m_desc != nullptr) {
			if (m_Linear) {
				ostr << std::setfill(' ');
				char small_desc[35 + 1] = {};
				std::strncpy(small_desc, m_desc, 35);

				ostr << std::left << std::setw(6) << m_sku << "| " << std::setw(35) << small_desc << " | " << std::right << std::setw(4) << m_quantity << " | " << std::setw(4) << m_neededQty << " |" << std::setw(8) << std::fixed << std::setprecision(2) << m_price << " |";
			}

			else {
				ostr << std::left << "AMA Item:" << std::endl
					<< m_sku << ": " << m_desc << std::endl
					<< "Quantity Needed: " << m_neededQty << std::endl
					<< "Quantity Available: " << m_quantity << std::endl
					<< "Unit Price: $" << m_price << std::endl
					<< "Needed Purchase Fund: $"
					<< std::fixed << std::setprecision(2) << m_price * (m_neededQty - m_quantity) << std::endl;
			}
		}
		else {
			ostr << m_status;
		}
		return ostr;
	}


	std::ifstream& Item::load(std::ifstream& ifstr) {
		delete[] m_desc;
		m_desc = nullptr;

		int sku, qty_available, qty_needed;
		double price;

		ifstr.clear();

		ifstr >> sku;
		ifstr.ignore(1000, '\t');

		const char* temp = ut.getCString(ifstr, '\t');
		if (temp == nullptr || ifstr.fail()) {
			m_status = "Input file stream read failed!";
			delete[] temp;
			return ifstr;
		}

		ifstr >> qty_available;
		ifstr.ignore(1000, '\t');

		ifstr >> qty_needed;
		ifstr.ignore(1000, '\t');

		ifstr >> price;

		m_desc = new char[std::strlen(temp) + 1];
		strcpy(const_cast<char*>(m_desc), temp);
		delete[] temp;

		m_sku = sku;
		m_quantity = qty_available;
		m_neededQty = qty_needed;
		m_price = price;
		clear();

		return ifstr;
	}


	std::istream& Item::read(std::istream& istr) {
		clear();

		std::cout << "AMA Item:" << std::endl;
		m_sku = readSku(istr);

		delete[] m_desc;
		m_desc = nullptr;

		istr.clear();
		istr.ignore(1000, '\n');
		char* temp = ut.getCString("Description: ");

		if (temp != nullptr) {
			m_desc = new char[std::strlen(temp) + 1];
			strcpy(const_cast<char*>(m_desc), temp);
			delete[] temp;
		}
		std::cout << "Quantity Needed: ";
		m_neededQty = ut.getInt(1, 9999);
		std::cout << "Quantity On Hand: ";
		m_quantity = ut.getInt(0, m_neededQty);
		std::cout << "Unit Price: $";
		m_price = ut.getDouble(0, 9999.00);

		return istr;
	}

	int Item::readSku(std::istream& istr) {
		std::cout << "SKU: ";
		return ut.getInt(40000, 99999);
	}

	std::ostream& operator<<(std::ostream& ostr, const Item& item) {
		return item.display(ostr);
	}

	std::istream& operator>>(std::istream& istr, Item& item) {
		return item.read(istr);
	}

}
