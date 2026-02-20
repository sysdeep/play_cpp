#pragma once
#include <string>
#include <cstdint>

struct SystemInfo
{
    uint Containers;
    uint ContainersRunning;
    uint ContainersPaused;
    uint ContainersStopped;
    uint Images;
    uint64_t MemTotal;
    std::string ServerVersion;

    static SystemInfo
    fromString(const std::string src);
};
