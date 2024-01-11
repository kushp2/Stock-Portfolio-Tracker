//ApiAccess.h

#pragma once
#include <string>
#include <curl/curl.h>

class ApiAccess {
public:
    ApiAccess(const std::string& apiKey);
    ~ApiAccess();

    std::string fetchStockData(const std::string& urlSymbol);

private:
    CURL* curl_;
    std::string apiKey_;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};