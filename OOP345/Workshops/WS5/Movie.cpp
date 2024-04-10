#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"

namespace seneca{
	Movie::Movie(const std::string& strMovie) {
		size_t startIndex{ 0 };
		size_t endIndex = strMovie.find(',');
		m_title = strMovie.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strMovie.find(',', startIndex);
		m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
		m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);
		m_yearOfRelease = std::stoi(strMovie.substr(startIndex, (endIndex - startIndex)));
		startIndex = endIndex + 1;
		endIndex = strMovie.find('\n', startIndex);
		m_description = strMovie.substr(startIndex, endIndex);
		m_description.erase(0, m_description.find_first_not_of(" \t\r\n"));
		m_description.erase(m_description.find_last_not_of(" \t\r\n") + 1);
	} 

	const std::string& Movie::title() const { return m_title;}
	
	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::right << std::setw(40) << movie.m_title << " | ";
		os << std::setw(4) << movie.m_yearOfRelease << " | ";
		os << std::left << std::setw(40) << movie.m_description << "\n";
		return os;
	}
}