#include "StudentManager.h"
#include <iostream>

StudentManager::StudentManager() {
    // Constructor implementation
}
void StudentManager::addStudent() {
Student student;

    student.input();
    students.push_back(student);
    std::cout<<"\n Student added successfully!\n";

}

void StudentManager::displayStudents(){
    if(students.empty()){
        std::cout << "No students to display.\n";
        return;
    }
    for(const Student& student : students){
        student.display();
        std::cout << "---------------------\n";
    }
}