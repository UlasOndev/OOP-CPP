/***********************************************************************
// Final project Milestone 5
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
   Ulas Ondev        2023-11-22
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"

#include <iomanip>
using namespace std;
namespace sdds {
	Utils ut;
	void Utils::testMode(bool testmode) {
		m_testMode = testmode;
	}

	void Utils::getSystemDate(int* year, int* mon, int* day) {
		if (m_testMode) {
			if (day) *day = sdds_testDay;
			if (mon) *mon = sdds_testMon;
			if (year) *year = sdds_testYear;
		}
		else {
			time_t t = std::time(NULL);
			tm lt = *localtime(&t);
			if (day) *day = lt.tm_mday;
			if (mon) *mon = lt.tm_mon + 1;
			if (year) *year = lt.tm_year + 1900;
		}
	}
	int Utils::daysOfMon(int month, int year) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
		return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Utils::copyString(char* dest, size_t destSize, const char* src) {
		size_t i = 0;
		while (i < destSize - 1 && src[i] != '\0') {
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}

	int Utils::getInt(const char* prompt) {
		int value;
		bool success = false;

		while (!success) {
			if (prompt != nullptr) {
				std::cout << prompt;
			}

			std::cin >> value;

			if (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid Integer, retry: ";
			}
			else {
				success = true;
			}
		}

		return value;
	}

	int Utils::getInt(int min, int max, const char* prompt) {
		int value;
		bool in_range = false;

		while (!in_range) {
			value = getInt(prompt);

			if (value < min || value > max) {
					std::cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
			}
			else {
				in_range = true;
			}
		}
		return value;
	}

	int Utils::getInt(std::istream& file) {
		int value;
		while (file >> value) {
			if (file.fail()) {
				file.clear();
				file.ignore(1000, '\n');
			}
			else {
				return value;
			}
		}
		return 0;
	}

	double Utils::getDouble(const char* prompt) {
		double value;
		bool success = false;

		while (!success) {
			if (prompt != nullptr) {
				std::cout << prompt;
			}

			std::cin >> value;

			if (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid number, retry: ";
			}
			else {
				success = true;
			}
		}
		return value;
	}

	double Utils::getDouble(double min, double max, const char* prompt) {
		double value;
		bool in_range = false;

		while (!in_range) {
			value = getDouble(prompt);

			if (value < min || value > max) {
					std::cout << "Value out of range [" << std::fixed << std::setprecision(2) << min << "<=val<=" << max << "]: ";
			}
			else {
				in_range = true;
			}
		}
		return value;
	}

	char* Utils::getCString(std::istream& input, char delimiter) {
		char* buffer = new char[360];
		int buffer_size = 360;
		bool success = false;

		while (!success) {
			if (!input.getline(buffer, buffer_size, delimiter)) {
				if (input.eof()) {
					delete[] buffer;
					return nullptr;
				}
				if (input.fail()) {
					input.clear();
					input.ignore(1000, delimiter);

					if (input.gcount() == buffer_size - 1) {
						char* new_buffer = new char[buffer_size * 2];
						std::strcpy(new_buffer, buffer);
						delete[] buffer;
						buffer = new_buffer;
						buffer_size *= 2;
						continue;
					}
						std::cout << "Invalid string, retry\n";
				}
			}
			else {
				success = true;
			}
		}

		char* value = new char[std::strlen(buffer) + 1];
		std::strcpy(value, buffer);
		delete[] buffer;

		return value;
	};

	char* Utils::getCString(const char* prompt, char delimiter) {
		char* buffer = new char[360];
		int buffer_size = 360;
		bool success = false;

		while (!success) {
			if (prompt != nullptr) {
				std::cout << prompt;
			}

			if (!std::cin.getline(buffer, buffer_size)) {
				if (std::cin.eof()) {
					delete[] buffer;
					return nullptr;
				}
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, delimiter);

					if (std::cin.gcount() == buffer_size - 1) {
						char* new_buffer = new char[buffer_size * 2];
						std::strcpy(new_buffer, buffer);
						delete[] buffer;
						buffer = new_buffer;
						buffer_size *= 2;
						continue;
					}

					if (std::cin.gcount() == 0) {
						delete[] buffer;
						return nullptr;
					}
						std::cout << "Invalid string, retry: ";
				}
			}
			else {
				success = true;
			}
		}

		char* value = new char[std::strlen(buffer) + 1];
		std::strcpy(value, buffer);
		delete[] buffer;

		return value;
	}
};