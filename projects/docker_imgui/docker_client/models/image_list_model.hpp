#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    struct ImageListModel
    {
        uint64_t Containers;
        uint64_t Created;
        std::string Id;
        // "Labels" : null,
        //    "ParentId" : "",
        // "RepoDigests" : [],
        std::vector<std::string> RepoTags;
        // "SharedSize" : -1,
        uint64_t Size;

        // static Image fromString(const std::string src);
        // static std::vector<Image> fromStringArray(const std::string src);
    };

}