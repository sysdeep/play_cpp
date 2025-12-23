#pragma once
#include <string>

struct DockerVersion
{
    std::string build_time;
    std::string kernel_version;

    static DockerVersion fromString(std::string src);
};