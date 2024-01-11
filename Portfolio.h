//Portfolio.h

#pragma once
#include <vector>
#include "Stock.h"

class Portfolio {
public:
	void addStock(const Stock& stock);					//adds a stock to the portfolio
	void removeStock(const std::string& symbol);		//removes a stock from the portfolio

	double getTotalValue() const;						//gets the total portfolio value
	double getPercentageChange() const;					//gets the percent change of the portfolio value
	std::vector<Stock> getStocks() const;							


private:
	std::vector<Stock> stocks_;							//holds the stocks in the portfolio
};