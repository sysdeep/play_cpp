#include "containers_parser.hpp"
#include "rapidjson/document.h"
#include <iostream>

docker::Container docker::parseContainer(const std::string &value){

    Container result{};

    return result;
}


/*
"[{
    \"Id\":\"28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba\",
    \"Names\":[\"/registry\"],
    \"Image\":\"kata/dev/registry:2\",
    \"ImageID\":\"sha256:a98a5e59fc04ef47a28c1119b48f3e7826fc7ff14b80641bcf0c4131b225360d\",
    \"Command\":\"/entrypoint.sh /etc/docker/registry/config.yml\",
    \"Created\":1764085053,\
    "Ports\":[
    {\"IP\":\"127.0.0.1\",\"PrivatePort\":5000,\"PublicPort\":5000,\"Type\":\"tcp\"},
    {\"IP\":\"172.28.1.1\",\"PrivatePort\":5000,\"PublicPort\":5000,\"Type\":\"tcp\"}],
    \"Labels\":{},
    \"State\":\"running\",
    \"Status\":\"Up 6 hours\",
    \"HostConfig\":{\"NetworkMode\":\"bridge\"},
    \"Health\":{\"Status\":\"none\",\"FailingStreak\":0},
    \"NetworkSettings\":{\"Networks\":{\"bridge\":{\"IPAMConfig\":null,\"Links\":null,\"Aliases\":null,\"DriverOpts\":null,\"GwPriority\":0,\"NetworkID\":\"569e76a7c3ae7318c08105dad7c591e4ffd484e56b15bc1172800e1967c62ba7\",\"EndpointID\":\"6016762d2dfc90141a4b991f3b8d4e3a67ed4eb3e9741f2954c682e51971bf1c\",\"Gateway\":\"172.27.0.1\",\"IPAddress\":\"172.27.0.2\",\"MacAddress\":\"fa:a2:f1:7d:a7:b6\",\"IPPrefixLen\":24,\"IPv6Gateway\":\"\",\"GlobalIPv6Address\":\"\",\"GlobalIPv6PrefixLen\":0,\"DNSNames\":null}}},
    \"Mounts\":[{\"Type\":\"volume\",\"Name\":\"docker-registry\",\"Source\":\"/home/var/lib/docker/volumes/docker-registry/_data\",\"Destination\":\"/var/lib/registry\",\"Driver\":\"local\",\"Mode\":\"z\",\"RW\":true,\"Propagation\":\"\"}]}]\n"
*/
std::vector<docker::Container> docker::parseContainers(const std::string &value){

    std::vector<docker::Container> result;

    rapidjson::Document document;
    document.Parse(value.c_str());

    if(document.IsArray()){
        for(auto const &record: document.GetArray()){
            docker::Container container{};

            if(record.HasMember("Id")){
                auto v = record["Id"].GetString();
                container.Id = std::string(v, record["Id"].GetStringLength());
            }

            if(record.HasMember("Image")){
                auto v = record["Image"].GetString();
                container.Image = std::string(v, record["Image"].GetStringLength());
            }

            if(record.HasMember("ImageID")){
                auto v = record["ImageID"].GetString();
                container.ImageID = std::string(v, record["ImageID"].GetStringLength());
            }

            if(record.HasMember("State")){
                auto v = record["State"].GetString();
                container.State = std::string(v, record["State"].GetStringLength());
            }

            if(record.HasMember("Status")){
                auto v = record["Status"].GetString();
                container.Status = std::string(v, record["Status"].GetStringLength());
            }

            if(record.HasMember("Names")){
                std::vector<std::string> names;
                for(auto const &name : record["Names"].GetArray()){
                    if(name.IsString()){
                        auto v = name.GetString();
                        auto vv = std::string(v, name.GetStringLength());
                        names.push_back(std::move(vv));
                    }
                }

                container.Names = names;
            }


            result.push_back(std::move(container));
        }
    }



    return result;
}
