#pragma once
#include <string>
#include "rapidjson/document.h"
#include "models/image_model.hpp"

namespace docker
{
    namespace parser
    {
        ImageModel parseImage(const std::string &src);
        ImageConfigModel parseImageConfig(const rapidjson::Value &value);
    }
}