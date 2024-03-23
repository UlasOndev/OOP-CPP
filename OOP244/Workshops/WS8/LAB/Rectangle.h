#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width; 
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* str, int width, int height);

		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;
	};

};
#endif //!SDDS_LINE_H

