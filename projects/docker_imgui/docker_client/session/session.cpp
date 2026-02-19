#include "session.hpp"
#include <iostream>

Session::Session() : host_uri("http:/v1.24"), is_remote(false)
{
    this->init();
}

Session::Session(std::string host_uri) : host_uri(host_uri), is_remote(true)
{
    this->init();
}

Session::~Session()
{
    curl_global_cleanup();
}

void Session::init()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

Response Session::get(std::string path)
{

    curl = curl_easy_init();
    if (!curl)
    {
        std::cout << "error while initiating curl" << std::endl;
        curl_global_cleanup();
        exit(1);
    }

    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");

    std::string readBuffer;
    std::string method_str("GET");

    if (!this->is_remote)
    {
        curl_easy_setopt(curl, CURLOPT_UNIX_SOCKET_PATH, "/var/run/docker.sock");
    }

    curl_easy_setopt(curl, CURLOPT_URL, (this->host_uri + path).c_str()); // work
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method_str.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    unsigned status = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
    curl_easy_cleanup(curl);

    // std::cout << "status: " << status << std::endl;
    // std::cout << readBuffer << std::endl;

    return std::make_pair(status, readBuffer);
}