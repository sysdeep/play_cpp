#pragma once
#include <string>
namespace docker
{

    struct DockerVersion
    {
        std::string version;
        std::string api_version;
        std::string build_time;
        std::string kernel_version;

        static DockerVersion fromString(std::string src);
    };

}