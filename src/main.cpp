#include <iostream>
#include "Database.h"

int main()
{
    Database database("database/student.db");

    if (!database.connect())
    {
        return 1;
    }

    std::string createTable = R"(
        CREATE TABLE IF NOT EXISTS students(
            id INTEGER PRIMARY KEY,
            firstName TEXT NOT NULL,
            lastName TEXT NOT NULL,
            age INTEGER,
            course TEXT
        );
    )";

    if(database.executeQuery(createTable))
    {
        std::cout << "Students table is ready.\n";
    }

    return 0;
}

// #include <iostream>
// #include "StudentManager.h"

// using namespace std;

// int main()
// {
//     StudentManager manager;
//     int choice;

//     do
//     {
//         cout << "\n=====================================\n";
//         cout << "     STUDENT MANAGEMENT SYSTEM\n";
//         cout << "=====================================\n";
//         cout << "1. Add Student\n";
//         cout << "2. Display Students\n";
//         cout << "3. Search Student\n";
//         cout << "4. Update Student\n";
//         cout << "5. Delete Student\n";
//         cout << "6. Exit\n";
//         cout << "=====================================\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             manager.addStudent();
//             break;

//         case 2:
//             manager.displayStudents();
//             break;

//         case 3:
//             manager.searchStudent();
//             break;

//         case 4:
//             manager.updateStudent();
//             break;

//         case 5:
//             manager.deleteStudent();
//             break;

//         case 6:
//             cout << "\nThank you for using the Student Management System!\n";
//             break;

//         default:
//             cout << "\nInvalid choice! Please try again.\n";
//         }

//     } while (choice != 6);

//     return 0;
// }