#pragma once
#include <string>
#include <cstdint>
#include "rapidjson/document.h"

namespace docker
{
    namespace parser
    {

        std::string processString(const rapidjson::Value &record, const char *name, const std::string default_value);

        int64_t processInt64(const rapidjson::Value &value);
        int64_t processInt64If(const rapidjson::Value &value, const char *name, int64_t default_value = 0);
        uint64_t processUint64(const rapidjson::Value &value);
        uint64_t processUint64If(const rapidjson::Value &value, const char *name, uint64_t default_value = 0);
        bool processBooleanIf(const rapidjson::Value &value, const char *name, bool default_value = false);
    }
}