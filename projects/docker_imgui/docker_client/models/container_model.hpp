#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    struct ContainerState
    {
        std::string Status;
        bool Running;
        bool Paused;
        bool Restarting;
        bool OOMKilled;
        bool Dead;
        uint64_t Pid;
        int64_t ExitCode;
        std::string Error;
        std::string StartedAt;
        std::string FinishedAt;
    };

    // тип монирования - volume
    struct ContainerMountVolume
    {
        std::string Type;
        std::string Name;
        std::string Source;
        std::string Destination;
        std::string Driver;
        std::string Mode;
        bool RW;
        std::string Propagation;
    };

    struct ContainerNetwork
    {
        std::string Key; // bridge

        std::string IPAddress;
        std::string Gateway;
        std::string MacAddress;

        // NOTE: добавить остальные поля если нужно - см. полную модель в парсере
    };

    struct ContainerNetworkSettings
    {
        std::vector<ContainerNetwork> Networks;
    };

    struct ContainerConfig
    {
        std::vector<std::string> Cmd;
        std::vector<std::string> Env;
        std::vector<std::string> Entrypoint;
        std::string Image;
    };

    struct ContainerModel
    {
        std::string Id;
        std::string Path;
        std::string Name;
        uint64_t RestartCount;
        ContainerState State;

        // std::vector<std::string> Names;
        // std::string Image;
        // std::string ImageID;
        // std::string State;
        // std::string Status;

        // volume mounts
        std::vector<ContainerMountVolume> MountVolumes;

        // TODO: bind mounts

        // network settings
        ContainerNetworkSettings NetworkSettings;

        // config
        ContainerConfig Config;
    };

}