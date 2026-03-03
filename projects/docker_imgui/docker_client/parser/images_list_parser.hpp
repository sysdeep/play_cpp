#pragma once
#include <vector>
#include "docker_client/models/image.hpp"

namespace docker
{
    namespace parser
    {
        std::vector<Image> parseImagesList(const std::string src);
    }
}