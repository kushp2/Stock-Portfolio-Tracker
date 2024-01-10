#include "ApiAccess.h"

#include <iostream>
#include <sstream>

ApiAccess::ApiAccess(const std::string& apiKey) : m_apiKey(apiKey), m_baseUrl("https://www.alphavantage.co/query?") {}

std::string ApiAccess::makeApiCall(const std::string& url) const {
    HINTERNET hInternet = InternetOpenA("MyAgent", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (!hInternet) {
        std::cerr << "Error opening internet session: " << GetLastError() << std::endl;
        return "";
    }

    HINTERNET hConnect = InternetConnectA(hInternet, "www.alphavantage.co", INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, 0, 0, 0);
    if (!hConnect) {
        InternetCloseHandle(hInternet);
        std::cerr << "Error connecting to Alpha Vantage: " << GetLastError() << std::endl;
        return "";
    }

    HINTERNET hRequest = HttpOpenRequestA(hConnect, "GET", url.c_str(), NULL, NULL, NULL, INTERNET_FLAG_RELOAD, 0);
    if (!hRequest) {
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
        std::cerr << "Error opening HTTP request: " << GetLastError() << std::endl;
        return "";
    }

    if (!HttpSendRequestA(hRequest, NULL, 0, NULL, 0)) {
        InternetCloseHandle(hRequest);
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
        std::cerr << "Error sending HTTP request: " << GetLastError() << std::endl;
        return "";
    }

    char buffer[1024];
    DWORD bytesRead;
    std::string response;
    while (InternetReadFile(hRequest, buffer, sizeof(buffer), &bytesRead)) {
        response.append(buffer, bytesRead);
    }

    InternetCloseHandle(hRequest);
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return response;
}

std::string ApiAccess::buildApiUrl(const std::string& endpoint, const std::string& symbol) const {
    return m_baseUrl + "function=" + endpoint + "&symbol=" + symbol + "&apikey=" + m_apiKey;
}

double ApiAccess::getRealTimePrice(const std::string& symbol) const {
    std::string url = buildApiUrl("GLOBAL_QUOTE", symbol);
    std::string response = makeApiCall(url);

    // Manually parse JSON response
    size_t latestPriceStart = response.find("\"latestPrice\":") + 14;  // Adjusted index for consistency
    size_t latestPriceEnd = response.find(",", latestPriceStart);
    std::string priceStr = response.substr(latestPriceStart, latestPriceEnd - latestPriceStart);

    // Convert extracted price string to double
    double price;
    try {
        std::stringstream ss(priceStr);
        ss >> price;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing price from response: " << e.what() << std::endl;
        return 0.0;
    }

    return price;
}

void ApiAccess::getRealTimePrices(const std::vector<std::string>& symbols, std::vector<double>& prices) const {
    for (const std::string& symbol : symbols) {
        prices.push_back(getRealTimePrice(symbol));
    }
}
