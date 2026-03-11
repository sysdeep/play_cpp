#include "image_history_parser.hpp"
#include "rapidjson/document.h"
#include "parser_utils.hpp"

using namespace docker;

std::vector<ImageHistoryModel> parser::parseImageHistory(const std::string &src)
{
    rapidjson::Document doc;
    doc.Parse(src.c_str());

    std::vector<ImageHistoryModel> result;

    if (doc.IsArray())
    {
        for (auto const &item : doc.GetArray())
        {
            ImageHistoryModel model{
                processString(item, "Id", ""),
                processString(item, "CreatedBy", ""),
                processUint64If(item, "Created", 0),
                processUint64If(item, "Size", 0),
                processStringsList(item, "Tags"),
            };
            result.push_back(std::move(model));
        }
    }

    return result;
}