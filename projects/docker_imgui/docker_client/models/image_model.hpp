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
        std::vector<std::string> Env;
        std::string StopSignal;
        std::string User;
        std::string WorkingDir;
    };

    struct ImageModel
    {
        std::string Id;
        std::string Created;
        uint64_t Size;
        std::vector<std::string> RepoTags;

        ImageConfigModel Config;
    };

}