#pragma once
#include <string>
#include <cstdint>
#include <vector>

struct Image
{
    uint Containers;
    uint Created;
    std::string Id;
    // "Labels" : null,
    //    "ParentId" : "",
    // "RepoDigests" : [],
    // "RepoTags" : ["nvchad:2"],
    // "SharedSize" : -1,
    uint64_t Size;

    static Image fromString(const std::string src);
    static std::vector<Image> fromStringArray(const std::string src);
};
