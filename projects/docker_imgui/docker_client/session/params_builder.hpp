#pragma once
#include <string>
#include <vector>
namespace docker
{
    class ParamsBuilder
    {
    public:
        ParamsBuilder();

        ParamsBuilder *add(std::string key, std::string value);
        std::string build();

    private:
        std::vector<std::pair<std::string, std::string>> params;
    };
}