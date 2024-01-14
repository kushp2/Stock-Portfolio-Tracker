#include "ApiWrapper.h"
#include "ApiAccess.h"
#include <msclr/marshal_cppstd.h>

namespace StockPortfolioApp
{
    ApiWrapper::ApiWrapper()
    {
        apiAccess = new ApiAccess();
    }

    ApiWrapper::~ApiWrapper()
    {
        delete apiAccess;
    }

    System::String^ ApiWrapper::FetchStockData(System::String^ symbol)
    {
        std::string symbolStr = msclr::interop::marshal_as<std::string>(symbol);
        std::string result = apiAccess->fetchStockData(symbolStr);

        return gcnew System::String(result.c_str());
    }
}
