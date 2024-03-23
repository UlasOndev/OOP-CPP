#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
    class Student {
    private:
        char* name; 
        int age;    

    public:
        Student();
        Student(const char* name, int age);
        Student(const Student& other);
        Student& operator=(const Student& other);
        virtual ~Student();
        void display() const;

    };

}

#endif //!SDDS_STUDENT_H
