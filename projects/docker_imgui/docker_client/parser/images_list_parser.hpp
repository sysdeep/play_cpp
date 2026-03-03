#pragma once
#include <vector>
#include "models/image_list_model.hpp"

namespace docker
{
    namespace parser
    {
        std::vector<ImageListModel> parseImagesList(const std::string src);
    }
}