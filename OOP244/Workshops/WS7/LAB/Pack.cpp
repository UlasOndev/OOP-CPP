#include "Pack.h"
namespace sdds {
	Pack::Pack(const char* content, int size, int unit_size, int num_of_units) : Container(content, size* unit_size, num_of_units* unit_size), m_size(unit_size > 0 ? unit_size : 0) {
		if (unit_size <= 0) {
			Container::setEmpty();
		}
	}

	int Pack::unit() const {
		return m_size;
	}

	int Pack::unitNo() const {
		return volume() / m_size;
	}

	int Pack::size() const {
		return capacity() / m_size;
	}

	void Pack::clear(int size, int unit_size, const char* content) {
		if (unit_size > 0) {
			m_size = unit_size;
			Container::clear(size * unit_size, content);
		}
		else Container::setEmpty();
	}

	int Pack::operator+=(int addUnits) {
		int addedUnits = addUnits * m_size;
		int addedCC = Container::operator+=(addedUnits);

		return addedCC / m_size;
	}
	int Pack::operator-=(int removeUnits) {
		int removeAmount = removeUnits * m_size;
		int removedCC = Container::operator-=(removeAmount);

		return removedCC / m_size;
	}

	std::ostream& Pack::print(std::ostream& ostr) const {
		if (*this) {
			Container::print(ostr);
			ostr << ", " << unitNo() << " in a pack of " << size();
		}
		return ostr;
	}

	std::istream& Pack::read(std::istream& istr) {
		if (!(*this)) {
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
			istr.ignore(1000, '\n');
			return istr;
		}

		int missingUnits = size() - unitNo();

		if (missingUnits > 0) {

			std::cout << "Add to ";
			print(std::cout);
			std::cout << "\n> ";

			int addUnits;

			while (!(istr >> addUnits) || addUnits < 1 || addUnits > missingUnits) {
				istr.clear();
				istr.ignore(1000, '\n');
				if (addUnits > missingUnits) {
					std::cout << "Value out of range [1<=val<=" << missingUnits << "]: ";
				}
			}

			int addedUnits = *this += addUnits;
			std::cout << "Added " << addedUnits << std::endl;
		}
		else {
			std::cout << "Pack is full!, Press <ENTER> to continue...." << std::endl;
			istr.ignore(1000, '\n');
		}

		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Pack& pack) {
		return pack.print(ostr);
	}

	std::istream& operator>>(std::istream& istr, Pack& pack) {
		return pack.read(istr);
	}
}