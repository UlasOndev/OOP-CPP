#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <iostream>
#include "Container.h"  

namespace sdds {
	class Pack : public Container {  
		int m_size; 
	public:
		Pack(const char* content = "", int size = 0, int unit_size = 330, int num_of_units = 0);

		int operator+=(int value);
		int operator-=(int value);

		int unit() const;  
		int unitNo() const;  
		int size() const; 

		void clear(int size, int unit_size, const char* content);

		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);


		friend std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
		friend std::istream& operator>>(std::istream& istr, Pack& pack);
	};
}

#endif //!SDDS_PACK_H
