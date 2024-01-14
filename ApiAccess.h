#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>
#include <curl/curl.h>

class ApiAccess
{
private:
    std::string apiKey_;
    CURL* curl_;

public:
    ApiAccess();
    ~ApiAccess();

    std::string fetchStockData(const std::string& symbol);

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
};
