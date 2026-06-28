#include <iostream>
#include "StudentManager.h"

using namespace std;

int main()
{
    StudentManager manager;
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     STUDENT MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addStudent();
            break;

        case 2:
            manager.displayStudents();
            break;

        case 3:
            cout << "\nThank you for using the Student Management System!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}