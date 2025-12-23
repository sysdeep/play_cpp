#pragma once

#include <string>
#include <curl/curl.h>

#include "containers.hpp"
#include "images.hpp"
#include "session/session.hpp"

class Client
{
public:
    Client();
    Client(std::string host);
    ~Client();

    Containers *containers;
    Images *images;

    void docker_version();
    void system_info();

private:
    std::string host;
    bool is_remote;

    Session *session;
    void init();
};