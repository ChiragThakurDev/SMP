#include "StudentManager.h"
#include <iostream>
#include <string>

StudentManager::StudentManager()
    : database("database/student.db")
{
    database.connect();

    std::string createTable = R"(
        CREATE TABLE IF NOT EXISTS students(
            id INTEGER PRIMARY KEY,
            first_name TEXT NOT NULL,
            last_name TEXT NOT NULL,
            age INTEGER,
            course TEXT
        );
    )";

    database.executeQuery(createTable);
}
void StudentManager::addStudent()
{
    Student student;

    student.input();

    if (database.addStudent(student))
    {
        std::cout << "\nStudent added successfully!\n";
    }
    else
    {
        std::cout << "\nFailed to add student!\n";
    }
}

void StudentManager::displayStudents()
{
    database.displayStudents();
}

void StudentManager::searchStudent()
{
    int id;

    std::cout << "Enter Student ID to search: ";
    std::cin >> id;

    database.searchStudent(id);
}

void StudentManager::updateStudent()
{
    Student student;

    int id;
    std::string firstName;
    std::string lastName;
    int age;
    std::string course;

    std::cout << "Enter Student ID to update: ";
    std::cin >> id;

    std::cout << "Enter New First Name: ";
    std::cin >> firstName;

    std::cout << "Enter New Last Name: ";
    std::cin >> lastName;

    std::cout << "Enter New Age: ";
    std::cin >> age;

    std::cout << "Enter New Course: ";
    std::cin >> course;

    student.setId(id);
    student.setFirstName(firstName);
    student.setLastName(lastName);
    student.setAge(age);
    student.setCourse(course);

    if (database.updateStudent(student))
    {
        std::cout << "\nStudent updated successfully!\n";
    }
    else
    {
        std::cout << "\nFailed to update student!\n";
    }
}
void StudentManager::deleteStudent()
{
    int id;

    std::cout << "Enter Student ID to delete: ";
    std::cin >> id;

    if (database.deleteStudent(id))
    {
        std::cout << "\nStudent deleted successfully!\n";
    }
    else
    {
        std::cout << "\nFailed to delete student!\n";
    }
}