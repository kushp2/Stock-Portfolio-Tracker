#pragma once
#include <string>


class Stock {
public:
	Stock(const std::string& symbol, double purchasePrice = 0.0);

	//variables
	std::string getSymbol() const;					//returns the stocks symbol
	double getCurrentPrice() const;					//returns the current stock price
	double getPurchasePrice() const;				//gets the purchase price of the stock
	void setCurrentPrice(double price);				//sets the prucase price
	int getQuantitiy() const;
	void setQuantity(int quantity);

private:
	std::string symbol_;							//holds the stock symbol
	double currentPrice_;							//holds the current price
	double purchasePrice_;							//holds the purchase price
	int quantity_;
};