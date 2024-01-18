//ApiAccess.cpp

#include "ApiAccess.h"
#include <iostream>
#include <curl/curl.h>

const std::string BASE_URL = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=";
const std::string KEY_PARAM = "WS6EM8MYALPWZ37O";
//if you are being limited, you can change your key
//key3: WS6EM8MYALPWZ37O
//key2: XZI3MKQDSPW5TKNN


ApiAccess::ApiAccess()
{
    
    apiKey_ = KEY_PARAM;
    curl_ = curl_easy_init();
}

ApiAccess::~ApiAccess()
{
    if (curl_)
    {
        curl_easy_cleanup(curl_);
    }
}

std::string ApiAccess::fetchStockData(const std::string& symbol)
{
    std::string result;
    std::string tempURL = BASE_URL + symbol + "&apikey=" + apiKey_;

    if (curl_){
        //sets up url
        curl_easy_setopt(curl_, CURLOPT_URL, tempURL.c_str());

        //sets ups the write callback to get the response
        curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &result);

        //sends the request
        CURLcode res = curl_easy_perform(curl_);

        //checks for errors for errors
        if (res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
    else{
        std::cerr << "Error initializing cURL." << std::endl;
    }

    //if the symbol does not exist, change the return value, else cleans up the data
    if (result.length() == 26)
        result = "The symbol " + symbol + " does not exist.";
    else {
        //cleans up the data
        result.erase(remove(result.begin(), result.end(), '\"'), result.end());
        result.erase(remove(result.begin(), result.end(), '{'), result.end());
        result.erase(remove(result.begin(), result.end(), '}'), result.end());
        result.erase(remove(result.begin(), result.end(), ','), result.end());
    }

    return result;
}


size_t ApiAccess::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}
