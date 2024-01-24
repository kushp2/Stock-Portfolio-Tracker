//UsersDB.cpp
//used to access the database

#include "UsersDB.h"
#include <string>
#include <msclr/marshal_cppstd.h>

namespace StockPortfolioApp {
    using namespace msclr::interop;

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

    //gets the username from the key, returns a nullptr if not found
    std::string& UsersDB::getUserFromKey(int key){
        static std::string emptyString = "";
        static std::string username = "";

        const char* selectSQL = "SELECT username FROM Users WHERE id = ?;";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
        
        if (rc != SQLITE_OK) {
            return emptyString; 
        }
        sqlite3_bind_int(stmt, 1, key);
        rc = sqlite3_step(stmt);
        
        if (rc == SQLITE_ROW) {
            const unsigned char* usernameCString = sqlite3_column_text(stmt, 0);
            if (usernameCString) {
                username = reinterpret_cast<const char*>(usernameCString);
            }
        }
        sqlite3_finalize(stmt);
        return username;
    }


    //returns the users portfolio data
    std::string& UsersDB::getPortfolioData(const std::string& username) {
        std::string portfolioData;

        std::string selectSQL = "SELECT Symbol, quantity, currentPrice, buyPrice FROM " + username + "_Portfolio;";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, selectSQL.c_str(), -1, &stmt, nullptr);

        if (rc == SQLITE_OK) {
            //loops through the result rows and appends the data
            while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
                const unsigned char* symbol = sqlite3_column_text(stmt, 0);
                int quantity = sqlite3_column_int(stmt, 1);
                double currentPrice = sqlite3_column_double(stmt, 2);
                double buyPrice = sqlite3_column_double(stmt, 3);

                // Format the data and append to portfolioData string
                portfolioData += std::to_string(quantity) + " " + reinterpret_cast<const char*>(symbol)
                    + " " + std::to_string(currentPrice) + " " + std::to_string(buyPrice) + "\n";
            }

            sqlite3_finalize(stmt);
        }

        return portfolioData;
    }


    //saves a stock from the portfolio grid to the database
    bool UsersDB::insertPortfolio(int key, System::String^ symbol, int quantity, double currentPrice, double buyPrice) {
        //gets the username
        std::string usernameStr = getUserFromKey(key);

        //sets the sql query
        std::string insertSQL = "INSERT INTO " + usernameStr + "_Portfolio (Symbol, quantity, currentPrice, buyPrice) VALUES (?, ?, ?, ?);";
        const char* insertSQLCStr = insertSQL.c_str();

        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, insertSQLCStr, -1, &stmt, nullptr);

        if (rc != SQLITE_OK) {
            return false;
        }

        //bind parameters
        sqlite3_bind_text(stmt, 1, msclr::interop::marshal_as<std::string>(symbol).c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, quantity);
        sqlite3_bind_double(stmt, 3, currentPrice);
        sqlite3_bind_double(stmt, 4, buyPrice);

        //executes the statment
        rc = sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        return (rc == SQLITE_DONE);
    }




    bool UsersDB::updatePortfolio(int key, System::String^ current_symbol, System::String^ updatedPrice) {
        std::string username = getUserFromKey(key);

        std::string symbol = msclr::interop::marshal_as<std::string>(current_symbol);
        std::string newPrice = msclr::interop::marshal_as<std::string>(updatedPrice);

        //construct the SQL query
        const char* updateSQL = ("UPDATE " + username + "_Portfolio SET currentPrice = " + newPrice +
            " WHERE Symbol = '" + symbol + "';").c_str();

        //execute the SQL query
        int rc = sqlite3_exec(db, updateSQL, nullptr, nullptr, nullptr);

        if (rc == SQLITE_OK) {
            //update successful
            return true;
        }
        else {
            //update fails
            return false;
        }
    }
}