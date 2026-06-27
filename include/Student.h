#ifndef STUDENT_H
#define STUDENT_H
#include<string>

class Student{
    private:
    int id;
    std::string firstName;
    int age;
    std::string lastName;
    std::string course;

    public:
    Student();

    void input();
    void display() const;
};

#endif
