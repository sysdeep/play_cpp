#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    struct Image
    {
        uint Containers;
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

    std::vector<Image> parseImages(const std::string src);
}