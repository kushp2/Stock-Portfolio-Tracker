//UsersDB.h
//used to access the database

#pragma once

#include <sqlite3.h>
#include <string>

namespace StockPortfolioApp {

    class UsersDB {
    public:
        UsersDB();                                                          //opens the db
        ~UsersDB();                                                         //closes the db

        std::string& getPortfolioData(const std::string& username);         //gets hte portfolio data from a user
        bool createPortfolio(const std::string& username);                  //creates a portfolio table with the username
        bool deletePortfolio(const std::string& username);                  //deletes the portfolio table with the username
        bool insertUser(const std::string& username);                       //inserts a new user into the Users table
        bool removeUser(const std::string& username);                       //removes a user from the Users table
        int getPrimaryKey(const std::string& username);                     //gets the primary key of a user from the table
        std::string& getUserFromKey(int key);                               //gets the username from the primary key
        bool insertPortfolio(int key, System::String^ symbol,               
            int quantity, double currentPrice, double buyPrice);            //inserts data into the users portfolio
        bool updatePortfolio(int key, System::String ^ current_symbol, 
            System::String^ updatedPrice);                                  //updates the current price of a stock in the portfolio
        



    private:
        sqlite3* db;
        const char* dbPath;                                                 //holds the path to the .db file
    };
}