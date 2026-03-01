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