#pragma once
#include <string>
#include <vector>
#include "rapidjson/document.h"
#include "models/image_history_model.hpp"

namespace docker
{
    namespace parser
    {
        std::vector<ImageHistoryModel> parseImageHistory(const std::string &src);
    }
}