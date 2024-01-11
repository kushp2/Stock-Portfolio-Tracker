//Stock.cpp

#include "Stock.h"

//constructor
Stock::Stock(const std::string& symbol, double currentPrice, double purchasePrice, int quantitiy)
	: symbol_(symbol), currentPrice_(currentPrice), purchasePrice_(purchasePrice), quantity_(quantitiy) {}

Stock::Stock()
	:symbol_("N/A"), currentPrice_(0.0), purchasePrice_(0.0), quantity_(0) {}


//get methods
std::string Stock::getSymbol() const {
	return symbol_;
}

double Stock::getCurrentPrice() const {
	return currentPrice_;
}

double Stock::getPurchasePrice() const {
	return purchasePrice_;
}

int Stock::getQuantitiy() const {
	return quantity_;
}


//set meathods
void Stock::setCurrentPrice(double price) {
	currentPrice_ = price;
}

void Stock::setQuantity(int quantitiy) {
	quantity_ = quantitiy;
}