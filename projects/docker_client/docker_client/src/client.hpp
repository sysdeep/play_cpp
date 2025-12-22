#pragma once

#include <string>
#include <curl/curl.h>

#include "containers.hpp"
#include "images.hpp"

class Client
{
public:
    Client();
    ~Client();

    Containers containers;
    Images images;

    void docker_version();
    void system_info();

private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
    }

    std::pair<unsigned int, std::string> make_request(std::string path);
};