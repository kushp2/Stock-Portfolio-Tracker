#pragma once

#include <windows.h>
#include <wininet.h>
#include <string>
#include <vector>

class ApiAccess {
public:
    // Constructor to initialize API key and base URL
    ApiAccess(const std::string& apiKey = "WS6EM8MYALPWZ37O");

    // Function to retrieve real-time price for a given symbol
    double getRealTimePrice(const std::string& symbol) const;

    // Function to retrieve real-time prices for multiple symbols
    void getRealTimePrices(const std::vector<std::string>& symbols, std::vector<double>& prices) const;

private:
    // Private member variables
    std::string m_apiKey;
    std::string m_baseUrl;

    // Private functions for P/Invoke and API interaction
    std::string makeApiCall(const std::string& url) const;
    std::string buildApiUrl(const std::string& endpoint, const std::string& symbol) const;
};