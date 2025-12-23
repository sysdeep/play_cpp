#include "client.hpp"
#include <string>
#include <iostream>

Client::Client()
{
    curl_global_init(CURL_GLOBAL_ALL);
    this->containers = Containers();
    this->images = Images();
}

Client::~Client()
{
    curl_global_cleanup();
}

void Client::docker_version()
{
    std::string path = "/version";

    auto res = this->make_request(path);
    std::cout << "status: " << res.first << std::endl;
    std::cout << res.second << std::endl;
}

void Client::system_info()
{
    std::string path = "/info";

    auto res = this->make_request(path);
    std::cout << "status: " << res.first << std::endl;
    std::cout << res.second << std::endl;
}

std::pair<unsigned int, std::string> Client::make_request(std::string path)
{
    struct curl_slist *headers = nullptr;
    // return requestAndParseJson(GET, path);
    CURL *curl{};
    CURLcode res{};
    curl = curl_easy_init();
    if (!curl)
    {
        std::cout << "error while initiating curl" << std::endl;
        curl_global_cleanup();
        exit(1);
    }

    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");

    std::string readBuffer;
    std::string host_url("http://172.28.2.1:2375");
    std::string method_str("GET");
    // if (!is_remote)
    // curl_easy_setopt(curl, CURLOPT_UNIX_SOCKET_PATH, "/var/run/docker.sock");
    curl_easy_setopt(curl, CURLOPT_UNIX_SOCKET_PATH, "/var/run/docker.sock");
    curl_easy_setopt(curl, CURLOPT_URL, ("http:/foo" + path).c_str()); // work
    // curl_easy_setopt(curl, CURLOPT_URL, ("http:/v1.24" + path).c_str());     // work
    // curl_easy_setopt(curl, CURLOPT_URL, (host_url + path).c_str());
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
};