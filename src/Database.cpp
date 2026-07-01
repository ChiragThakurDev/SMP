#include <iostream>
#include "Database.h"

Database::Database(const std::string &dbName)
{
    this->dbName = dbName;
    db = nullptr;
}

Database::~Database()
{
    disconnect();
}

bool Database::connect()
{
    int result = sqlite3_open(dbName.c_str(), &db);

    if (result != SQLITE_OK)
    {
        std::cerr << "Failed to connect to database.\n";
        std::cerr << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::cout << "Connected to the database successfully." << std::endl;
    return true;
}

void Database::disconnect()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
        std::cout << "Disconnected from the database." << std::endl;
    }
}

bool Database::executeQuery(const std::string &query)
{
    char *errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        query.c_str(),
        nullptr,
        nullptr,
        &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL Error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

bool Database::addStudent(const Student &student)
{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "INSERT INTO students(id, first_name, last_name, age, course) "
        "VALUES (?, ?, ?, ?, ?);";

    std::cout << "\nPreparing SQL:\n"
              << sql << std::endl;

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement." << std::endl;
        std::cerr << "SQLite Error: "
                  << sqlite3_errmsg(db)
                  << std::endl;

        if (stmt != nullptr)
            sqlite3_finalize(stmt);

        return false;
    }

    sqlite3_bind_int(stmt, 1, student.getId());

    sqlite3_bind_text(
        stmt,
        2,
        student.getFirstName().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_text(
        stmt,
        3,
        student.getLastName().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_int(
        stmt,
        4,
        student.getAge());

    sqlite3_bind_text(
        stmt,
        5,
        student.getCourse().c_str(),
        -1,
        SQLITE_TRANSIENT);

    result = sqlite3_step(stmt);

    if (result != SQLITE_DONE)
    {
        std::cerr << "Failed to insert student." << std::endl;
        std::cerr << "SQLite Error: "
                  << sqlite3_errmsg(db)
                  << std::endl;

        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);

    std::cout << "Student inserted successfully!" << std::endl;

    return true;
}

bool Database::displayStudents()
{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "SELECT id, first_name, last_name, age, course FROM students;";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare SELECT statement.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::cout << "\n========================================\n";
    std::cout << "         STUDENT RECORDS\n";
    std::cout << "========================================\n";

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::cout << "ID: "
                  << sqlite3_column_int(stmt, 0) << std::endl;

        std::cout << "First Name: "
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))
                  << std::endl;

        std::cout << "Last Name: "
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))
                  << std::endl;

        std::cout << "Age: "
                  << sqlite3_column_int(stmt, 3)
                  << std::endl;

        std::cout << "Course: "
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))
                  << std::endl;

        std::cout << "----------------------------------------\n";
    }

    sqlite3_finalize(stmt);

    return true;
}

bool Database::searchStudent(int id)

{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "SELECT id, first_name, last_name, age, course "
        "FROM students WHERE id = ?;";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare search statement.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Bind the ID entered by the user
    sqlite3_bind_int(stmt, 1, id);

    result = sqlite3_step(stmt);

    if (result == SQLITE_ROW)
    {
        std::cout << "\n========== Student Found ==========\n";

        std::cout << "ID: "
                  << sqlite3_column_int(stmt, 0) << std::endl;

        std::cout << "First Name: "
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))
                  << std::endl;

        std::cout << "Last Name: "
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2))
                  << std::endl;

        std::cout << "Age: "
                  << sqlite3_column_int(stmt, 3)
                  << std::endl;

        std::cout << "Course: "
                  << reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4))
                  << std::endl;

        sqlite3_finalize(stmt);
        return true;
    }

    std::cout << "\nStudent not found.\n";

    sqlite3_finalize(stmt);
    return false;
}
bool Database::updateStudent(const Student &student)
{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "UPDATE students "
        "SET first_name = ?, last_name = ?, age = ?, course = ? "
        "WHERE id = ?;";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare UPDATE statement.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1,
        student.getFirstName().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_text(stmt, 2,
        student.getLastName().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_int(stmt, 3,
        student.getAge());

    sqlite3_bind_text(stmt, 4,
        student.getCourse().c_str(),
        -1,
        SQLITE_TRANSIENT);

    sqlite3_bind_int(stmt, 5,
        student.getId());

    result = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (result != SQLITE_DONE)
    {
        std::cout << "Failed to update student.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::cout << "Student updated successfully!\n";
    return true;
}

bool Database::deleteStudent(int id)
{
    sqlite3_stmt *stmt = nullptr;

    std::string sql =
        "DELETE FROM students WHERE id = ?;";

    int result = sqlite3_prepare_v2(
        db,
        sql.c_str(),
        -1,
        &stmt,
        nullptr);

    if (result != SQLITE_OK)
    {
        std::cout << "Failed to prepare DELETE statement.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, id);

    result = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (result != SQLITE_DONE)
    {
        std::cout << "Failed to delete student.\n";
        std::cout << "SQLite Error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    if (sqlite3_changes(db) == 0)
    {
        std::cout << "Student ID not found.\n";
        return false;
    }

    std::cout << "Student deleted successfully!\n";
    return true;
}