#include "UsersDB.h"
#include <string>

namespace StockPortfolioApp {
    //contructor: opens the database
    UsersDB::UsersDB() : db(nullptr) {
        //opens the db
        dbPath = "UsersDB.db";
        int rc = sqlite3_open(dbPath, &db);

        //creates a table if it does not exist
        const char* createTableSQL = "CREATE TABLE IF NOT EXISTS Users("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "username TEXT NOT NULL,"
            "date_added DATETIME DEFAULT CURRENT_TIMESTAMP);";
        rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, nullptr);
    }

    //deconstructor: closes the database
    UsersDB::~UsersDB() {
        if (db) {
            sqlite3_close(db);
        }
    }


    //creates a table
    bool UsersDB::createPortfolio(const std::string& username) {
        int primaryKey = getPrimaryKey(username);

        //if the user exists
        if (primaryKey != -1) {
            //sets the query to make a portfolio table
            std::string createTableSQL = "CREATE TABLE IF NOT EXISTS " + username + "_Portfolio ( "
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "Symbol TEXT NOT NULL,"
                "quantity INTEGER NOT NULL,"
                "currentPrice REAL NOT NULL,"
                "buyPrice REAL NOT NULL"
                ");";
            int rc = sqlite3_exec(db, createTableSQL.c_str(), nullptr, nullptr, nullptr);
            return rc == SQLITE_OK;
        }
        else {
            return false;
        }
    }

    //deletes a portfolio table
    bool UsersDB::deletePortfolio(const std::string& username) {
        std::string portfolioTable = username + "_Portfolio";
        std::string dropTableSQL = "DROP TABLE IF EXISTS " + portfolioTable + ";";
        int rc = sqlite3_exec(db, dropTableSQL.c_str(), nullptr, nullptr, nullptr);
        return rc == SQLITE_OK;
    }

    //inserts a user into the Users table
    bool UsersDB::insertUser(const std::string& username) {
        const char* insertSQL = "INSERT INTO Users (username) VALUES (?);";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            return false;
        }
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        return rc == SQLITE_DONE;
    }

    //removes the user from the User table
    bool UsersDB::removeUser(const std::string& username) {
        int primaryKey = getPrimaryKey(username);

        //if the user exists
        if (primaryKey != -1) {
            const char* deleteSQL = "DELETE FROM Users WHERE id = ?;";
            sqlite3_stmt* stmt;
            int rc = sqlite3_prepare_v2(db, deleteSQL, -1, &stmt, nullptr);
            if (rc != SQLITE_OK) {
                return false;
            }
            sqlite3_bind_int(stmt, 1, primaryKey);
            rc = sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            return rc == SQLITE_DONE;
        }
        else {
            // User doesn't exist
            return false;
        }
    }

    //gets the primary key for an entry, returns -1 if not found
    int UsersDB::getPrimaryKey(const std::string& username) {
        const char* selectSQL = "SELECT id FROM Users WHERE username = ?;";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
        if (rc != SQLITE_OK) {
            return -1;  // Indicate error
        }
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
        rc = sqlite3_step(stmt);
        int primaryKey = -1;
        if (rc == SQLITE_ROW) {
            primaryKey = sqlite3_column_int(stmt, 0);  // Get the ID from the first column
        }
        sqlite3_finalize(stmt);
        return primaryKey;
    }
}