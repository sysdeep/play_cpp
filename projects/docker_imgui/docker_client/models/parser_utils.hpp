#pragma once
#include <string>
#include "rapidjson/document.h"

namespace docker
{
    std::string processString(const rapidjson::Value &record, const char *name, const std::string default_value);
}