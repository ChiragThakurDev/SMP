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
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
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
            manager.searchStudent();
            break;

        case 4:
            manager.updateStudent();
            break;

        case 5:
            cout << "\nThank you for using the Student Management System!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}