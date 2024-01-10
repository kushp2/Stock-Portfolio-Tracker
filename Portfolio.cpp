#include "Portfolio.h"


//adds a stock to the portfolio
void Portfolio::addStock(const Stock& stock) {
	stocks_.push_back(stock);
}

//removes a stock from the portfolio
void Portfolio::removeStock(const std::string& symbol) {
    //loops through every stock and removes the one with the matching name
    for (auto it = stocks_.begin(); it != stocks_.end(); ++it) {
        if (it->getSymbol() == symbol) {
            stocks_.erase(it);
            break;
        }
    }
}

double Portfolio::getTotalValue() const {
    double totalValue = 0.0;
    for (const Stock& stock : stocks_) {
        totalValue += stock.getCurrentPrice() * stock.getQuantitiy();
    }
    return totalValue;
}

//gets the total percent change in the account
double Portfolio::getPercentageChange() const {
    double initialValue = 0;                //holds the ammount of money the stocks were purchased for
    double currentValue = getTotalValue();  //holds the current value of the stocks
    double change;                          //holds the final return value
    
    //avoids searching an empty vector
    if (stocks_.empty()) {
        return 0;
    }

    //loops through each stock and gets the price each stock was purchased for
    for (const Stock& stock: stocks_) {
        initialValue += stock.getPurchasePrice() * stock.getQuantitiy();
    }

    //avoids division by 0
    if (initialValue == 0){
        return 0;
    }

    change = (currentValue - initialValue) / initialValue * 100;

    return change;
}

