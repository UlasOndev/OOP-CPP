#ifndef CARINVENTORY_H
#define CARINVENTORY_H

namespace sdds {
    class CarInventory {
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;

    public:
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
        ~CarInventory();

        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;

    private:
        void resetInfo();
    };

    int find_similar(CarInventory car[], const int num_cars);
}

#endif //!CARINVENTORY_H
