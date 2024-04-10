#define _CRT_SECURE_NO_WARNINGS
#include "Toy.h"
#include <iostream>
#include <string>
#include <iomanip>
namespace seneca {
    Toy::Toy() {
        m_orderID = 0;
        m_maxItems = 0;
        m_price = 0;
    }
    void Toy::update(int numItems) {
        m_maxItems = numItems;
    }
    Toy::Toy(const std::string& toy) {
        std::string tempToy = toy;
        size_t pos = tempToy.find(':');
        m_orderID = std::stoi(tempToy.substr(0, pos));
        tempToy.erase(0, pos + 1);
        pos = tempToy.find(':');
        m_name = tempToy.substr(0, pos);
        m_name.erase(0, m_name.find_first_not_of(' '));
        m_name.erase(m_name.find_last_not_of(' ') + 1);
        tempToy.erase(0, pos + 1);
        pos = tempToy.find(':');
        m_maxItems = std::stoi(tempToy.substr(0, pos));
        tempToy.erase(0, pos + 1);

        m_price = std::stod(tempToy);
    }
    std::ostream& operator<<(std::ostream& ostr, const Toy& rhs) {
        double total = rhs.m_price * rhs.m_maxItems;
        double totalIncTax = total * rhs.m_tax;

        ostr << "Toy"
            << std::setw(8) << rhs.m_orderID << ":"
            << std::right << std::setw(18) << rhs.m_name
            << std::setw(3) << rhs.m_maxItems
            << " items" << std::setw(8) << std::fixed << std::setprecision(2) << rhs.m_price
            << "/item  subtotal:" << std::setw(7) << std::fixed << std::setprecision(2) << total
            << " tax:" << std::setw(6) << std::fixed << std::setprecision(2) << totalIncTax
            << " total:" << std::setw(7) << std::fixed << std::setprecision(2) << (total + totalIncTax) << std::endl;
            
        return ostr;
    }
}