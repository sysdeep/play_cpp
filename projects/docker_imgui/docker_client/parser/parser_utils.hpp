#pragma once
#include <string>
#include <cstdint>
#include "rapidjson/document.h"

namespace docker
{
    namespace parser
    {

        std::string processString(const rapidjson::Value &record, const char *name, const std::string default_value);

        uint64_t processUint64(const rapidjson::Value &value);
    }
}