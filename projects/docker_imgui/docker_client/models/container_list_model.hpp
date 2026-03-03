#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    struct ContainerListModel
    {
        std::string Id;
        std::vector<std::string> Names;
        std::string Image;
        std::string ImageID;
        std::string State;
        std::string Status;
        uint64_t Created;

        // uint64_t Containers;
        // "Labels" : null,
        //    "ParentId" : "",
        // "RepoDigests" : [],
        // "SharedSize" : -1,
        // uint64_t Size;

        // static Image fromString(const std::string src);
        // static std::vector<Image> fromStringArray(const std::string src);
    };

}