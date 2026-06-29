#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
    private:
    std::vector<Student> students;

    public:
        StudentManager();
        void addStudent();
        void displayStudents();
        void searchStudent();
        void updateStudent();
};

#endif // STUDENTMANAGER_H