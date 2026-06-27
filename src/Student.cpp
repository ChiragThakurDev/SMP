#include <iostream>
#include "Student.h"

Student::Student()
{
    id = 0;
    age = 0;
}

void Student::input()
{
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cout << "Enter Course: ";
    std::cin >> course;
}

void Student::display() const
{
    std::cout << "Student Details:" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Course: " << course << std::endl;

}
