#include "docker_version.hpp"
// #include "nlohmann/json.hpp"
#include <iostream>

using namespace docker;
// using json = nlohmann::json;

/*
{
    "Platform": {
        "Name":"Docker Engine - Community"
    },
    "Version":"29.2.1",
    "ApiVersion":"1.53",
    "MinAPIVersion":"1.44",
    "Os":"linux",
    "Arch":"amd64",
    "Components":[
        {
            "Name":"Engine",
            "Version":"29.2.1",
            "Details":{
                "ApiVersion":"1.53",
                "Arch":"amd64",
                "BuildTime":"2026-02-02T17:17:09.000000000+00:00",
                "Experimental":"false",
                "GitCommit":"6bc6209",
                "GoVersion":"go1.25.6",
                "KernelVersion":"6.8.0-94-generic",
                "MinAPIVersion":"1.44",
                "Os":"linux"
            }
        },
        {
            "Name":"containerd",
            "Version":"v2.2.1",
            "Details": {
                    "GitCommit":"dea7da592f5d1d2b7755e3a161be07f43fad8f75"
            }
        },
        {
            "Name":"runc",
            "Version":"1.3.4",
            "Details": {
                "GitCommit":"v1.3.4-0-gd6d73eb8"
            }
        },
        {
            "Name":"docker-init",
            "Version":"0.19.0",
            "Details":{"GitCommit":"de40ad0"}
        }
    ],
    "GitCommit":"6bc6209",
    "GoVersion":"go1.25.6",
    "KernelVersion":"6.8.0-94-generic",
    "BuildTime":"2026-02-02T17:17:09.000000000+00:00"
}
*/
DockerVersion DockerVersion::fromString(std::string src)
{
    std::cout << src << std::endl;
    // json data = json::parse(src);
    // std::cout << data["BuildTime"] << std::endl;

    DockerVersion result;

    // result.build_time = data["BuildTime"];
    // result.kernel_version = data["KernelVersion"];
    // result.version = data["Version"];
    // result.api_version = data["ApiVersion"];

    return result;
}