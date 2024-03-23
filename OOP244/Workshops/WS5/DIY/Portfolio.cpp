/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


	Portfolio::Portfolio() {
		emptyPortfolio();
	}

	void Portfolio::emptyPortfolio()
	{
		m_value = 0;
		m_stock[0] = 0;
		m_type = 'E';
	}
	Portfolio::Portfolio(double value, const char* stock, char type) {
		emptyPortfolio();
		if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
			m_value = value;
			m_type = type;
			strcpy(m_stock, stock);
		}
	}

	void Portfolio::dispPortfolio() const {
		cout << " ";
		cout.width(10);
		cout << (const char*)(*this);
		cout << " | ";
		cout << "Value: ";
		cout.width(10);
		cout << double(*this);
		cout << " | ";
		cout << " Type: ";
		cout << char(*this);
	}
	std::ostream& Portfolio::display() const {

		if (~*this) {
			cout << " Portfolio  |  Bad-NG |";
			dispPortfolio();
		}
		else if (*this) {
			cout << " Portfolio  |  Active |";
			dispPortfolio();

		}
		else {
			cout << " Portfolio  |  EMPTY  |";
			dispPortfolio();
		}
		return cout;
	}

	Portfolio::operator double() const {
		return m_value;
	}

	Portfolio::operator const char* () const {
		return m_stock;
	}

	Portfolio::operator char() const {
		return m_type;
	}

	Portfolio::operator bool() const {
		bool check = false;
		if (m_type == 'G' || m_type == 'V' || m_type == 'I'){
			check = true;
		}
		return check;
	}

	Portfolio& Portfolio::operator+=(double valuePortfolio) {
		if (*this && valuePortfolio >= 0){
			m_value += valuePortfolio;
		}
		return *this;
	}

	Portfolio& Portfolio::operator-=(double valuePortfolio) {
		if (*this && valuePortfolio >= 0){
			m_value -= valuePortfolio;
		}
		return *this;
	}

	bool Portfolio::operator ~() const {
		bool check = false;
		if (m_value < 0){
			check = true;
		}
		return check;
	}

	Portfolio& Portfolio::operator<<(Portfolio& rhs) {
		if (*this && rhs){
			m_value += rhs.m_value;
			rhs.emptyPortfolio();
		}
		return *this;
	}

	Portfolio& Portfolio::operator>>(Portfolio& rhs) {
		if (*this && rhs){
			rhs.m_value += m_value;
			emptyPortfolio();
		}
		return *this;
	}

	double operator+(const Portfolio& lhs, const Portfolio& rhs) {
		double sum = 0.0;
		if (lhs && rhs){
			sum = double(lhs) + double(rhs);
		}
		return sum;
	}

	double &operator+=(double& lhs, const Portfolio& rhs) {
		if (rhs){
			lhs += double(rhs);
		}
		return lhs;
	}
}