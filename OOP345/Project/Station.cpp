#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"

namespace seneca {
    size_t Station::m_widthField = 0u;
    int Station::id_generator = 0;

    Station::Station(const std::string& str){
        m_stationID = ++id_generator;
        Utilities temp;
        bool more = true;
        size_t next_pos = 0u;

        m_item = temp.extractToken(str, next_pos, more);
        m_nextSerial = stoi(temp.extractToken(str, next_pos, more));
        m_stock = stoi(temp.extractToken(str, next_pos, more));
        m_widthField = m_widthField > temp.getFieldWidth() ? m_widthField : temp.getFieldWidth();
        m_description = temp.extractToken(str, next_pos, more);
    }

    const std::string& Station::getItemName() const{ return m_item; }

    size_t Station::getNextSerialNumber(){ return m_nextSerial++;}

    size_t Station::getQuantity() const{ return m_stock;}

    void Station::updateQuantity(){
        if (m_stock > 0) m_stock--;
    }

    void Station::display(std::ostream& os, bool full) const {
        os << std::right << std::setw(3) << std::setfill('0') << m_stationID
            << " | " << std::left << std::setw(m_widthField + 1) << std::setfill(' ')
            << m_item << "| " << std::right << std::setfill('0') << std::setw(6)
            << m_nextSerial << std::setfill(' ') << " | ";
        if (!full) os << std::endl;
        else os << std::setw(4) << m_stock << " | " << std::left << m_description << std::endl;
    }
}