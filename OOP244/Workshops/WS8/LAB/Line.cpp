#include <iostream>
#include <string>
#include <iomanip>
#include "Line.h"

using namespace std;

namespace sdds {
	Line::Line():  LblShape(), m_length(0) {};
	Line::Line(const char* str, int len): LblShape(str){
		m_length = len;
	};

	void Line::getSpecs(std::istream& is) {
		
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');

	};
	void Line::draw(std::ostream& os) const{
		
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			int i = 0;
			while ( i < m_length) {
				os << '=';
				i++;
			}
		}
	};
}