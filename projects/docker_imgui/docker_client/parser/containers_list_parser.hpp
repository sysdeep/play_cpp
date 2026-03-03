#pragma once
#include <vector>
#include "models/container_list_model.hpp"

namespace docker
{
    namespace parser
    {
        std::vector<ContainerListModel> parseContainersList(const std::string src);
    }
}