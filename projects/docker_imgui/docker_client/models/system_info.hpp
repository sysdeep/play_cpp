#pragma once
#include <string>

struct SystemInfo
{
    uint Containers;
    uint ContainersRunning;
    uint ContainersPaused;
    uint ContainersStopped;
    uint Images;

    static SystemInfo fromString(const std::string src);
};
