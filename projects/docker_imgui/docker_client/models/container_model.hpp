#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace docker
{

    // "State" : {
    //     "Status" : "running",
    //     "Running" : true,
    //     "Paused" : false,
    //     "Restarting" : false,
    //     "OOMKilled" : false,
    //     "Dead" : false,
    //     "Pid" : 4591,
    //     "ExitCode" : 0,
    //     "Error" : "",
    //     "StartedAt" : "2026-03-05T07:08:32.952693854Z",
    //     "FinishedAt" : "2026-03-04T15:42:18.255986124Z"
    // },

    struct ContainerState
    {
        std::string Status;
        bool Running;
        bool Paused;
        bool Restarting;
        bool OOMKilled;
        bool Dead;
        uint64_t Pid;
        uint64_t ExitCode;
        std::string Error;
        std::string StartedAt;
        std::string Finished;
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
    };

}