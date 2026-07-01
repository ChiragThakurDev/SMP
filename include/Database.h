#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite3.h"
#include "Student.h"
#include <vector>

class Database
{
private:
    sqlite3 *db;
    std::string dbName;

public:
    Database(const std::string &dbName);
    ~Database();

    bool connect();
    void disconnect();

    bool executeQuery(const std::string &query);

    bool addStudent(const Student &student);
    bool displayStudents();
    bool searchStudent(int id);
    bool updateStudent(const Student &student);
    bool deleteStudent(int id);
};

#endif