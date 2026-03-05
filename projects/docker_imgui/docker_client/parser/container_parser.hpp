#pragma once
#include "models/container_model.hpp"

namespace docker
{
    namespace parser
    {
        ContainerModel parseContainer(const std::string &src);
    }
}