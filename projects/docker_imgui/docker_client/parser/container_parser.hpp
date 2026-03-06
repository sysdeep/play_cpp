#pragma once
#include <rapidjson/document.h>
#include "models/container_model.hpp"

namespace docker
{
    namespace parser
    {
        ContainerModel parseContainer(const std::string &src);
        ContainerState parseContainerState(const rapidjson::Value &value);
        ContainerMountVolume parseContainerMountVolume(const rapidjson::Value &value);

        ContainerNetworkSettings parseContainerNetworkSettings(const rapidjson::Value &value);
        ContainerNetwork parseContainerNetwork(const rapidjson::Value &value, const std::string &key);

        ContainerConfig parseContainerConfig(const rapidjson::Value &value);
    }
}