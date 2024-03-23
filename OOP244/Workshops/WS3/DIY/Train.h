#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
    static const int MIN_TIME = 700;
    static const int MAX_TIME = 2300;
    static const int MAX_NO_OF_PASSENGERS = 1000;
    class Train {
        char* name;
        int passengers;
        int departureTime;
    public:
        Train();
        Train(const char* name, int passengers, int departureTime);
        ~Train();
        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        void finalize();
        bool isInvalid() const;
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;
        bool load(int& notBoarded);
        bool updateDepartureTime();
        bool transfer(const Train& from);
    };

}

#endif //!SDDS_TRAIN_H
