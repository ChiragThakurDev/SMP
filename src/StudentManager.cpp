#include "StudentManager.h"
#include <iostream>

StudentManager::StudentManager()
{
    // Constructor implementation
}
void StudentManager::addStudent()
{
    Student student;

    student.input();
    students.push_back(student);
    std::cout << "\n Student added successfully!\n";
}

void StudentManager::displayStudents()
{
    if (students.empty())
    {
        std::cout << "No students to display.\n";
        return;
    }
    for (const Student &student : students)
    {
        student.display();
        std::cout << "---------------------\n";
    }
}

void StudentManager::searchStudent()
{
    int searchId;
    std::cout << "Enter Student ID to search: ";
    std::cin >> searchId;

    for (const Student &student : students)
    {
        if (student.getId() == searchId)
        {
            std::cout << "Student found:\n";
            student.display();
            return;
        }
    }
    std::cout << "Student with ID " << searchId << " not found.\n";
}
void StudentManager::updateStudent()
{
    int updateId;
    std::cout << "Enter Student ID to update: ";
    std::cin >> updateId;

    for (Student &student : students)
    {
        if (student.getId() == updateId)
        {
            std::cout << "Student found. Enter new details:\n";
            student.input();
            std::cout << "Student updated successfully!\n";
            return;
        }
    }
    std::cout << "Student with ID " << updateId << " not found.\n";
}

void StudentManager::deleteStudent()
{
    int deleteId;
    std::cout << "Enter Student ID to delete: ";
    std::cin >> deleteId;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getId() == deleteId)
        {
            students.erase(it);
            std::cout << "Student with ID " << deleteId << " deleted successfully.\n";
            return;
        }
    }
    std::cout << "Student with ID " << deleteId << " not found.\n";
}