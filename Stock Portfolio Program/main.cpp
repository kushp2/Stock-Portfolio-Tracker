// main.cpp

#include "main.h"
#include <iostream>


//constructor
StockPortfolioApp::StockPortfolioApp() : apiAccess("WS6EM8MYALPWZ37O") {
  
}

//destructor
StockPortfolioApp::~StockPortfolioApp() {
   
}


//main logic of the application
void StockPortfolioApp::run() {
    std::string symbol;
    //prompts the user for a stock symbol
    while (symbol != "exit")
    {
        //prompts the user for input
        std::cout << "Enter stock symbol: ";
        std::cin >> symbol;
        std::cout << '\n' << '\n';

        //gets data from the API using ApiAccess and displays it
        std::string responseData = apiAccess.fetchStockData(symbol);
        std::cout << "Stock Information for symbol " << symbol << ":\n" << responseData << std::endl;
        std::cout << '\n' << '\n';
    }

}


//entry point of the program
int main() {
    //creates an instance of your application and runs
    StockPortfolioApp app;
    app.run();

    return 0;
}
