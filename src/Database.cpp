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
        std::cerr << "Failed to connect to the database: " << sqlite3_errmsg(db) << std::endl;
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
    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errorMessage);
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}