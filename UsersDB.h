#pragma once

#include <sqlite3.h>
#include <string>

namespace StockPortfolioApp {

    class UsersDB {
    public:
        UsersDB();                                                          //opens the db
        ~UsersDB();                                                         //closes the db

        bool createPortfolio(const std::string& username);                  //creates a portfolio table with the username
        bool deletePortfolio(const std::string& username);                  //deletes the portfolio table with the username
        bool insertUser(const std::string& username);                       //inserts a new user into the Users table
        bool removeUser(const std::string& username);                       //removes a user from the Users table
        int getPrimaryKey(const std::string& username);                     //gets the primary key of a user from the table



    private:
        sqlite3* db;
        const char* dbPath;                                                 //holds the path to the .db file                                               
    };
}