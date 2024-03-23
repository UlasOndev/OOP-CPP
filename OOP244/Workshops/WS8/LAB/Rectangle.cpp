#include <iostream>
#include <iomanip>
#include "Rectangle.h"
#include <cstring>

using namespace std;
namespace sdds {
	Rectangle::Rectangle() :  LblShape(), m_width(0), m_height(0) {};
	Rectangle::Rectangle(const char* str, int width, int height) : LblShape(str) {
		
		m_height = height;
		m_width = width;
		if (m_height < 3 || m_width < (int)strlen(label() + 2)) {
			m_width = 0;
			m_height = 0;
		}
	};

	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >>  m_width;
		is.ignore();
		is >> m_height;
		is.ignore(1000, '\n');
		

	};
	void Rectangle::draw(std::ostream& os) const {
		if (m_width > 0 && m_height > 0 && label() != nullptr) {
			os << '+';
			for (int i = 0; i < m_width - 2; i++) {
				os << '-';
			}
			os << '+' << endl;
			os << "|" ;
			os << left << setw(m_width - 2) << setfill(' ') << label();
			os << "|" << endl;

			for (int i = 0; i < m_height - 3; i++) {
				os << "| ";
				os << right << setw(m_width - 2) << " |" << endl;
			}

			os << '+';
			for (int i = 0; i < m_width - 2; i++) {
				os << '-';
			}
			os << '+';
		}
	};
}