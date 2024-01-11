// main.h

#pragma once

#include "Stock.h"
#include "ApiAccess.h"
#include "Portfolio.h"

class StockPortfolioApp {
public:
    StockPortfolioApp();
    ~StockPortfolioApp();

    void run();

private:
    // Declare any members or additional functionality you need
    // For example, you might have instances of Stock and ApiAccess.
    Stock stock;
    ApiAccess apiAccess;
    Portfolio portfolio;
};
