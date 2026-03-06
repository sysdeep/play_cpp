#pragma once
#include <rapidjson/document.h>
#include "models/container_model.hpp"

namespace docker
{
    namespace parser
    {
        ContainerModel parseContainer(const std::string &src);
        ContainerState parseContainerState(const rapidjson::Value &value);
    }
}