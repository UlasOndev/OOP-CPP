/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_PORTFOLIO_H
#define SDDS_PORTFOLIO_H
#include <iostream>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       void emptyPortfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       Portfolio& operator+=(double valuePortfolio);
       Portfolio& operator-=(double valuePortfolio);
       bool operator ~() const;
       Portfolio& operator<<(Portfolio& rhs);
       Portfolio& operator>>(Portfolio& rhs);
   };
   double operator+(const Portfolio& lhs, const Portfolio& rhs);
   double &operator+=(double& lhs, const Portfolio& rhs);
}
#endif //!SDDS_PORTFOLIO_H