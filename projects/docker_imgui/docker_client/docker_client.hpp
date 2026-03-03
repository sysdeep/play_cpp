#pragma once

#include <string>
#include <curl/curl.h>

#include "sections/containers.hpp"
#include "sections/images.hpp"
#include "sections/system.hpp"
#include "session/session.hpp"
#include "models/docker_version.hpp"

namespace docker
{
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

}