#include "Stock.h"

//constructor
Stock::Stock(const std::string& symbol, double purchasePrice)
	: symbol_(symbol), currentPrice_(0.0), purchasePrice_(purchasePrice) {}


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