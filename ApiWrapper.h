#pragma once

#include "ApiAccess.h"
#include <msclr/marshal_cppstd.h>

namespace StockPortfolioApp
{
    public ref class ApiWrapper
    {
    private:
        ApiAccess* apiAccess;

    public:
        ApiWrapper();
        ~ApiWrapper();

        System::String^ FetchStockData(System::String^ symbol);
    };
}
