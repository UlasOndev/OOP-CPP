#pragma once
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <iostream>
#include <iomanip>
#include <fstream>
namespace seneca{
	const unsigned int ARR_SIZE = 6;
	class SpellChecker{
		std::string m_badWords[ARR_SIZE]{};
		std::string m_goodWords[ARR_SIZE]{};
		size_t m_replacements[ARR_SIZE]{ 0 };

	public:
		SpellChecker() = default;
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif //!SENECA_SPELLCHECKER_H