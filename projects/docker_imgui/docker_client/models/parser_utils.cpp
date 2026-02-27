#include "parser_utils.hpp"

std::string docker::processString(const rapidjson::Value &record, const char *name, const std::string default_value)
{
    if (!record.IsObject())
    {
        return "Error - record no object";
    }

    if (record.HasMember(name))
    {
        auto len = record[name].GetStringLength();
        return std::string(record[name].GetString());
    }

    return default_value;
}