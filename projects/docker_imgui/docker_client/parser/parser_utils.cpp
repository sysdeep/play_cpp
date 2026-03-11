#include "parser_utils.hpp"

using namespace docker;
std::string parser::processString(const rapidjson::Value &record, const char *name, const std::string default_value)
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

std::vector<std::string> parser::processStringsList(const rapidjson::Value &record, const char *name)
{
    std::vector<std::string> result{};
    if (record.HasMember(name))
    {
        if (record[name].IsArray())
        {
            for (auto const &val : record[name].GetArray())
            {
                if (val.IsString())
                {
                    std::string res(val.GetString(), val.GetStringLength());
                    result.push_back(std::move(res));
                }
            }
        }
    }
    return result;
}

int64_t parser::processInt64(const rapidjson::Value &value)
{
    if (value.IsInt64())
    {
        int64_t i64 = value.GetInt64();
        return static_cast<uint64_t>(i64);
    }

    if (value.IsInt())
    {
        int i = value.GetInt();
        return static_cast<uint64_t>(i);
    }

    throw std::runtime_error("value is not int");
}

int64_t parser::processInt64If(const rapidjson::Value &value, const char *name, int64_t default_value)
{
    if (value.HasMember(name))
    {
        return processInt64(value[name]);
    }

    return default_value;
}

uint64_t parser::processUint64(const rapidjson::Value &value)
{
    if (value.IsUint64())
    {
        return value.GetUint64();
    }

    if (value.IsUint())
    {
        unsigned u = value.GetUint();
        return static_cast<uint64_t>(u);
    }

    if (value.IsInt64())
    {
        int64_t i64 = value.GetInt64();
        return static_cast<uint64_t>(i64);
    }

    if (value.IsInt())
    {
        int i = value.GetInt();
        return static_cast<uint64_t>(i);
    }

    if (value.IsDouble())
    {
        double d = value.GetDouble();
        return static_cast<uint64_t>(d);
    }

    throw std::runtime_error("value is not number");

    // else
    // {
    //     std::cout << "Value is not a number" << std::endl;
    // }
}

uint64_t parser::processUint64If(const rapidjson::Value &value, const char *name, uint64_t default_value)
{
    if (value.HasMember(name))
    {
        return processUint64(value[name]);
    }

    return default_value;
}

bool parser::processBooleanIf(const rapidjson::Value &value, const char *name, bool default_value)
{
    if (value.HasMember(name))
    {
        if (value[name].IsBool())
        {
            return value[name].GetBool();
        }
        return default_value;
    }
    return default_value;
}

// void processValue(const Value& value) {
//     if (value.IsUint64()) {
//         uint64_t u64 = value.GetUint64();
//         std::cout << "Value as uint64_t: " << u64 << std::endl;
//     } else if (value.IsUint()) {
//         unsigned u = value.GetUint();
//         std::cout << "Value as unsigned: " << u << std::endl;
//     } else if (value.IsInt64()) {
//         int64_t i64 = value.GetInt64();
//         std::cout << "Value as int64_t: " << i64 << std::endl;
//     } else if (value.IsInt()) {
//         int i = value.GetInt();
//         std::cout << "Value as int: " << i << std::endl;
//     } else if (value.IsDouble()) {
//         double d = value.GetDouble();
//         // Note: uint64_t might lose precision when converted to double.
//         std::cout << "Value as double: " << d << std::endl;
//     } else {
//         std::cout << "Value is not a number" << std::endl;
//     }
// }