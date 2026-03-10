#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    struct ImageConfigModel
    {
        std::vector<std::string> Cmd;
        std::vector<std::string> Entrypoint;
    };

    struct ImageModel
    {
        std::string Id;
        std::vector<std::string> RepoTags;
        uint64_t Size;

        ImageConfigModel Config;
    };

}