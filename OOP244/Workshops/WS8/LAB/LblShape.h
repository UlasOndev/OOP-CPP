#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label{nullptr}; 

	protected:
		const char* label() const;
	public:

		LblShape();
		LblShape(const char* newLabel);
		~LblShape();

		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;

		void getSpecs(std::istream& is) override;

	};
}
#endif // !SDDS_LBLSHAPE_H

