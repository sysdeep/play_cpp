#include "containers_list_parser.hpp"
#include "rapidjson/document.h"
#include "parser_utils.hpp"

using namespace docker;

std::vector<ContainerListModel> parser::parseContainersList(const std::string src)
{
    rapidjson::Document document;
    document.Parse(src.c_str());

    std::vector<ContainerListModel> results;

    if (document.IsArray())
    {
        for (auto const &record : document.GetArray())
        {
            ContainerListModel result{};

            // // Containers
            // if (record.HasMember("Containers"))
            //     result.Containers = processUint64(record["Containers"]);

            // Id
            result.Id = processString(record, "Id", "Error");

            // Image
            result.Image = processString(record, "Image", "Error");

            // ImageID
            result.ImageID = processString(record, "ImageID", "Error");

            // State
            result.State = processString(record, "State", "Error");

            // Status
            result.Status = processString(record, "Status", "Error");

            // Names
            if (record.HasMember("Names"))
            {
                std::vector<std::string> names;
                if (record["Names"].IsArray())
                {
                    for (auto const &val : record["Names"].GetArray())
                    {
                        if (val.IsString())
                        {
                            std::string res(val.GetString(), val.GetStringLength());
                            names.push_back(std::move(res));
                        }
                    }
                }
                result.Names = names;
            }

            // // Size
            // if (record.HasMember("Size"))
            //     result.Size = processUint64(record["Size"]);

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
    "Id":"28cf1320d2ba4408e389e996ba2dc1e3fab489205dd5d34aba7fe55c3e9b3fba",
    "Names":["/registry"],
    "Image":"kata/dev/registry:2",
    "ImageID":"sha256:a98a5e59fc04ef47a28c1119b48f3e7826fc7ff14b80641bcf0c4131b225360d",
    "Command":"/entrypoint.sh /etc/docker/registry/config.yml",
    "Created":1764085053,
    "Ports":[{
        "IP":"127.0.0.1",
        "PrivatePort":5000,
        "PublicPort":5000,
        "Type":"tcp"
    },{
        "IP":"172.28.1.1",
        "PrivatePort":5000,
        "PublicPort":5000,
        "Type":"tcp"
    }],
    "Labels":{},
    "State":"running",
    "Status":"Up 6 hours",
    "HostConfig":{"NetworkMode":"bridge"},
    "Health":{"Status":"none","FailingStreak":0},
    "NetworkSettings":{"Networks":{"bridge":{"IPAMConfig":null,"Links":null,"Aliases":null,"DriverOpts":null,"GwPriority":0,"NetworkID":"e4118249b095027f2131adbff0c32cdbdeb9651a2ad6f5aa51d36d3f476ff5a0","EndpointID":"9c679835f27f17dad1ea22f0532cd46ead1a521372be896460ff155ecb7c20b6","Gateway":"172.27.0.1","IPAddress":"172.27.0.2","MacAddress":"9a:93:5b:91:fd:af","IPPrefixLen":24,"IPv6Gateway":"","GlobalIPv6Address":"","GlobalIPv6PrefixLen":0,"DNSNames":null}}},
    "Mounts":[{"Type":"volume","Name":"docker-registry","Source":"/home/var/lib/docker/volumes/docker-registry/_data","Destination":"/var/lib/registry","Driver":"local","Mode":"z","RW":true,"Propagation":""}]}]
*/