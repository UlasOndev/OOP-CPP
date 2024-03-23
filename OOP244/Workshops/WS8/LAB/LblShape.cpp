
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "LblShape.h"
#include <cstring>

using namespace std;

namespace sdds {
	
	const char* LblShape::label() const {
		return m_label;
	};

	LblShape::LblShape(): m_label(nullptr) {};\
	
	LblShape::LblShape(const char* newLabel) {
		if (newLabel != nullptr && newLabel[0] != '\0') {
			m_label = new char[strlen(newLabel) + 1];
			strcpy(m_label, newLabel);
		}

	};

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	};

	void LblShape::getSpecs(std::istream& is) {
		
		string labelStr;
		getline(is, labelStr , ',');

		delete[] m_label; 
		m_label = new char[labelStr.length() + 1];
		strcpy(m_label, labelStr.c_str());

	};
}