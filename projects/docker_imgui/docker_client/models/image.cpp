#include "image.hpp"
#include "rapidjson/document.h"
#include <iostream>
#include "parser_utils.hpp"

using namespace docker;

// Image Image::fromString(const std::string src)
// {
//     rapidjson::Document document;
//     document.Parse(src.c_str());

//     Image result = Image{};

//     if (document.HasMember("Containers"))
//         result.Containers = document["Containers"].GetUint();

//     // if (document.HasMember("ContainersRunning"))
//     //     result.ContainersRunning = document["ContainersRunning"].GetUint();

//     // if (document.HasMember("ContainersPaused"))
//     //     result.ContainersPaused = document["ContainersPaused"].GetUint();

//     // if (document.HasMember("ContainersStopped"))
//     //     result.ContainersStopped = document["ContainersStopped"].GetUint();

//     // if (document.HasMember("Images"))
//     //     result.Images = document["Images"].GetUint();

//     // if (document.HasMember("MemTotal"))
//     //     result.MemTotal = document["MemTotal"].GetUint64();

//     // if (document.HasMember("ServerVersion"))
//     // {
//     //     auto res = document["ServerVersion"].GetString();
//     //     result.ServerVersion = std::string(res, document["ServerVersion"].GetStringLength());
//     // }

//     return result;
// }

std::vector<Image> docker::parseImages(const std::string src)
{
    rapidjson::Document document;
    document.Parse(src.c_str());

    std::vector<Image> results;

    if (document.IsArray())
    {
        for (auto const &record : document.GetArray())
        {
            Image result = Image{};

            // Containers
            if (record.HasMember("Containers"))
                result.Containers = processUint64(record["Containers"]);

            // Id
            result.Id = processString(record, "Id", "Error");

            // RepoTags
            if (record.HasMember("RepoTags"))
            {
                std::vector<std::string> names;
                if (record["RepoTags"].IsArray())
                {
                    for (auto const &val : record["RepoTags"].GetArray())
                    {
                        if (val.IsString())
                        {

                            std::string res(val.GetString(), val.GetStringLength());
                            names.push_back(std::move(res));
                        }
                    }
                }
                result.RepoTags = names;
            }

            // Size
            if (record.HasMember("Size"))
                result.Size = processUint64(record["Size"]);

            // Created
            if (record.HasMember("Created"))
                result.Created = processUint64(record["Created"]);

            results.push_back(std::move(result));
        }
    }

    return results;
}

/*
[
    {
        "Containers":1,
        "Created":1768385602,
        "Id":"sha256:1aae88c4cca561e1d31d7a9e1d2f04c090e5fa3cdc55acc2f8b7be221b645aaa",
        "Labels":null,
        "ParentId":"",
        "RepoDigests":[],
        "RepoTags":["nvchad:2"],
        "SharedSize":-1,
        "Size":404395173
    },{
        "Containers":0,
        "Created":1768385146,
        "Id":"sha256:6fffa536f7a906e40627a11a5106d9408d2b9a88c2f907a7c60f87d0f54658ac",
        "Labels":null,
        "ParentId":"",
        "RepoDigests":[],
        "RepoTags":[],
        "SharedSize":-1,
        "Size":371952117
    },{
        "Containers":0,
        "Created":1768384143,
        "Id":"sha256:a90002e0caae5a441226859bade255a70a873efd0d225aa8dff26d58eb08bb55",
        "Labels":null,
        "ParentId":"",
        "RepoDigests":[],
        "RepoTags":[],
        "SharedSize":-1,
        "Size":367962190
    },{
        "Containers":0,
        "Created":1768299345,
        "Id":"sha256:3d6e5b51fd1f55de1322a4514bd1da0bb76e68387d16de8b3f917a49936203df",
        "Labels":{"org.opencontainers.image.ref.name":"ubuntu","org.opencontainers.image.version":"22.04"},
        "ParentId":"",
        "RepoDigests":["172.28.1.1:5000/kaspersky/kata/test/appliance_pytest@sha256:83f73fa2c8dc358a64de771e4b3cae7c8c7001d4a513f786c8f8cac8dcacd6c8"],
        "RepoTags":[
            "172.28.1.1:5000/kaspersky/kata/test/appliance_pytest:1768299348",
            "172.28.1.1:5000/kaspersky/kata/test/appliance_pytest:fc59a97",
            "172.28.1.1:5000/kaspersky/kata/test/appliance_pytest:latest",
            "kaspersky/kata/test/appliance_pytest:fc59a97"
        ],
        "SharedSize":-1,
        "Size":1299169830
    }
*/