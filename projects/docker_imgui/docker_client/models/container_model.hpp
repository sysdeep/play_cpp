#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    struct ContainerModel
    {
        std::string Id;
        std::string Path;
        // std::vector<std::string> Names;
        // std::string Image;
        // std::string ImageID;
        // std::string State;
        // std::string Status;
        // uint64_t Created;
    };

}