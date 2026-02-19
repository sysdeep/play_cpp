#pragma once
#include <string>
#include <curl/curl.h>

using Response = std::pair<unsigned int, std::string>; // code, text

class Session
{
public:
    Session();
    Session(std::string host_uri);
    ~Session();

    // request methods
    Response get(std::string path);

private:
    std::string host_uri;
    bool is_remote;
    CURL *curl{};
    CURLcode res{};

    void init();

    // curl
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
    }
};