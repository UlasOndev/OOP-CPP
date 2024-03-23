/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.cpp
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
#include <iomanip>
#include "Date.h"
#include "Utils.h"

namespace sdds {
	bool Date::validate() {
		int current_year;

		ut.getSystemDate(&current_year);

		if (m_year == -1 || m_month == -1 || m_day == -1) {
			isSet = false;
			std::cout << "Invalid date value";
			return false;
		}

		if (m_year < current_year || m_year > MAX_YEAR_VALUE) {
			isSet = false;
			status = "Invalid year in date";
			status = 1;
			return false;
		}

		if (m_month < 1 || m_month > MAX_MONTH_VALUE) {
			isSet = false;
			status = "Invalid month in date";
			status = 2;
			return false;
		}

		if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
			isSet = false;
			status = "Invalid day in date";
			status = 3;
			return false;
		}

		isSet = true;
		status.clear();
		return true;
	}

	int Date::unique_date_value() const {
		return m_year * 372 + m_month * 31 + m_day;
	}

	Date::Date() {
		int year, month, day;

		ut.getSystemDate(&year, &month, &day);

		m_year = year;
		m_month = month;
		m_day = day;
	}

	Date::Date(int date_value) {
		int current_year;
		ut.getSystemDate(&current_year);

		if (date_value >= 10000000) {  
			m_year = date_value / 10000; 
			m_month = (date_value / 100) % 100; 
			m_day = date_value % 100; 
			isSet = true;
		}

		else if (date_value >= 10000) {  
			m_year = 2000 + (date_value / 10000);
			m_month = (date_value / 100) % 100; 
			m_day = date_value % 100;
			isSet = true;
		}

		else if (date_value >= 101) { 
			m_year = current_year;
			m_day = date_value % 100; 
			isSet = true;
		}
		else {
			int year, month, day;
			ut.getSystemDate(&year, &month, &day);

			m_year = year;
			m_month = month;
			m_day = day;
			isSet = false;
		}
	}

	Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day) {
		validate();
	}

	bool Date::operator==(Date& other) const {
		return unique_date_value() == other.unique_date_value();
	}

	bool Date::operator!=(const Date& other) const {
		return !(*this == other);
	}

	bool Date::operator<(Date& other) const {
		return unique_date_value() < other.unique_date_value();
	}

	bool Date::operator>(Date& other) const {
		return unique_date_value() > other.unique_date_value();
	}

	bool Date::operator<=(const Date& other) const {
		return !(*this > other);
	}

	bool Date::operator>=(const Date& other) const {
		return !(*this < other);
	}

	Date::operator bool() const {
		return state() && isSet;
	}

	const Status& Date::state() const {
		return status;
	}

	Date& Date::formatted(bool f) {
		m_formatted = f;
		return *this;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		if (m_formatted)
			ostr << std::setfill('0') << std::setw(4) << m_year << "/" << std::setw(2) << std::right << m_month << "/" << std::setw(2) << m_day;
		else
			ostr << std::setfill('0') << std::setw(2) << m_year % 100 << std::setw(2) << m_month << std::setw(2) << m_day;
		return ostr;
	}

	std::istream& Date::read(std::istream& istr) {
		const int date_value = ut.getInt();

		const Date temp(date_value);

		if (temp) {
			*this = temp;
		}
		else {
			istr.setstate(std::ios::failbit);
			status = "Invalid date format";
		}

		return istr;
	}

	std::ifstream& Date::load(std::ifstream& ifstr) {
		int date_value, current_year;

		ut.getSystemDate(&current_year);

		ifstr.ignore(1000, '\t');
		ifstr.ignore(1000, '\t');
		ifstr.ignore(1000, '\t');
		ifstr.ignore(1000, '\t');
		ifstr.ignore(1000, '\t');

		ifstr >> date_value;

		if (ifstr.fail()) {
			status = "Error reading date from file";
			ifstr.setstate(std::ios::failbit);
		}
		else {
			if (date_value < 10000) {
				m_year = current_year;
				m_month = date_value / 100;
				m_day = date_value % 100;
				isSet = true;
			}
			else {
				m_year = date_value / 10000;
				m_month = (date_value / 100) % 100;
				m_day = date_value % 100;
				isSet = true;
			}

			if (!validate()) {
				ifstr.setstate(std::ios::failbit);
			}
		}

		return ifstr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& date) {
		return date.read(istr);
	}
}