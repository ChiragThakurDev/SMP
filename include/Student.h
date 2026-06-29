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

    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    std::string getCourse() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setAge(int age);
    void setCourse(const std::string& course);
};

#endif
