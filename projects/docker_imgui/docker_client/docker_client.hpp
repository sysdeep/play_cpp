#pragma once

#include <string>
#include <curl/curl.h>

#include "entites/containers.hpp"
#include "entites/images.hpp"
#include "entites/system.hpp"
#include "session/session.hpp"
#include "models/docker_version.hpp"

class DockerClient
{
public:
    DockerClient();
    DockerClient(std::string host);
    ~DockerClient();

    Containers *containers;
    Images *images;
    System *system;

    DockerVersion docker_version();

private:
    std::string host;
    bool is_remote;

    Session *session;
    void init();
};