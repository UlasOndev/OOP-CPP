#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm> 
#include <iomanip>
#include "CustomerOrder.h"

namespace seneca {
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& str){
        Utilities temp;
        bool more = true;
        size_t pos = 0u;
        m_name = temp.extractToken(str, pos, more);
        m_product = temp.extractToken(str, pos, more);
        std::string listOfItems = "";
        size_t count = 0u;
        do{
           std::string tmp = temp.extractToken(str, pos, more);
           if (listOfItems.length() > 0) listOfItems += Utilities::getDelimiter();
           listOfItems += tmp;
           count++;
        } while (more);
        m_lstItem = new Item * [count];
        m_cntItem = count;
        pos = 0;
        count = 0;
        more = true;
        do{
           std::string tmp = temp.extractToken(listOfItems, pos, more);
           m_lstItem[count++] = new Item(tmp);
        } while (more);
        if (m_widthField < temp.getFieldWidth()) m_widthField = temp.getFieldWidth();
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& src){ throw false;}

    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : m_name{}, m_product{}, m_cntItem{}, m_lstItem{ nullptr }{
        *this = std::move(src);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept{
        if (this != &src) {
            m_name = src.m_name;
            m_product = src.m_product;
            for (size_t i = 0u; i < m_cntItem; i++) {
                delete m_lstItem[i];
                m_lstItem[i] = nullptr;
            }
            delete[] m_lstItem;
            m_lstItem = nullptr;
            m_cntItem = src.m_cntItem;
            m_lstItem = src.m_lstItem;

            src.m_name = "";
            src.m_product = "";
            src.m_cntItem = 0u;
            src.m_lstItem = nullptr;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder(){
        for (size_t i = 0; i < m_cntItem; i++){
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        size_t count = 0;
        for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_isFilled) count++;
        }
        return count == m_cntItem;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const{
        size_t itemCount = 0;
        size_t filledCount = 0;
        for (size_t i = 0; i < m_cntItem; i++){
            if (m_lstItem[i]->m_itemName == itemName){
                itemCount++;
                if (m_lstItem[i]->m_isFilled) filledCount++;
            }
        }
        return itemCount == filledCount;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os){
        for (size_t i = 0; i < m_cntItem; i++){
            if (m_lstItem[i]->m_isFilled == false && m_lstItem[i]->m_itemName == station.getItemName()){
                if (station.getQuantity() > 0){
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << std::setw(11) << std::right;
                    os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    break;
                }
                else  os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::left << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
            if (m_lstItem[i]->m_isFilled) os << "FILLED" << std::endl;
            else os << "TO BE FILLED" << std::endl;
        }
    }
}