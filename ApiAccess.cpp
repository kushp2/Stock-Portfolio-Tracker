//ApiAccess.cpp

#include "ApiAccess.h"
#include <iostream>
#include <curl/curl.h>

const std::string KEY = "WS6EM8MYALPWZ37O";
const std::string BASE_URL = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=";

ApiAccess::ApiAccess(const std::string& apiKey) : apiKey_(apiKey) {
    curl_ = curl_easy_init();
}

ApiAccess::~ApiAccess() {
    if (curl_) {
        curl_easy_cleanup(curl_);
    }
}

std::string ApiAccess::fetchStockData(const std::string& urlSymbol) {
    std::string result;
    std::string tempURL = BASE_URL + urlSymbol + "&apikey=" + KEY;

    if (curl_) {
        //sets the url
        curl_easy_setopt(curl_, CURLOPT_URL, tempURL.c_str());

        //sets the write callback to get the response
        curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &result);


        //performs the request
        CURLcode res = curl_easy_perform(curl_);

        //checks for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
    else {
        std::cerr << "Error initializing cURL." << std::endl;
    }

    //if the symbol does not exist, it changes the return value
    if (result.length() == 26)
        result = "The symbol " + urlSymbol + " does not exist.";

    return result;
}

size_t ApiAccess::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}
